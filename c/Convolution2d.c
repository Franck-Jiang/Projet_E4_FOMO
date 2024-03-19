#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "array.h"

int DEFAULT_DIM[2] = {1,1};

int* getResShape(   int* input_shape, int input_dim,
                    int* filtre_shape, int filtre_dim){

    /**
     * Renvoie les dimensions de la matrice issue de la convolution
     * des deux matrices input et filtre
     ***/
    int* resultat = (int*) malloc(3 * sizeof(int)); 
    if (input_dim != 2 || filtre_dim != 2) {
        printf("Convolution erreur dim\n");
        return malloc(0);
    }
    else {
        resultat[2] = 2;
        printf("Resultat_shape init OK\n");
        resultat[0] = input_shape[0] - ceil( filtre_shape[0]/2.0 );
        resultat[1] = input_shape[1] - ceil( filtre_shape[1]/2.0 );
        printf("a %d\n", filtre_shape[1]);
        printf("b %f\n", filtre_shape[1]/2.0);
        printf("c %f\n", ceil(filtre_shape[1]/2.0));
        printf("getres %d %d ", resultat[0], resultat[1]);
    }
    return resultat;
    }

void convolution2d( double* input, int* input_shape, int input_dim, 
                    double* filtre, int* filtre_shape, int filtre_dim, 
                    double* resultat, int* resultat_shape, int resultat_dim ) {

    if (input_dim != 2 || filtre_dim != 2) {
        printf("Convolution erreur dim\n");
    }
    else {
        printf("Dimensions: %d, %d\n", resultat_shape[0], resultat_shape[1]);
        // printf("OK\n");
        for (int i = 0; i < resultat_shape[0]; i++) {
            for (int j = 0; j < resultat_shape[1]; j++) {
                resultat[i*resultat_shape[0] + j] = 0;
                // printf("i=%d < %d, j=%d < %d\n", i, resultat.m, j, resultat.n);
                for (int k = 0; k < filtre_shape[0]; k++) {
                    for (int l = 0; l < filtre_shape[1]; l++) {
                        // printf("i=%d, j=%d, k=%d, l=%d\n",i,j,k,l);
                        if (i + k < input_shape[1] && j + l < input_shape[1]){
                            resultat[i * resultat_shape[1] + j] += input[(i + k) * input_shape[1] + j + l] * filtre[k * filtre_shape[1] + l];
                            // printf("%.2f\n", resultat[i * resultat_shape[1] + j]);
                        }
                    }
                }
            }
        }
    }
}

int main(void){
    int shape_mat1[2] = {5,5};
    int dim_mat1 = 2;
    double* mat1 = (double*) malloc(shape_mat1[0]*shape_mat1[1] * sizeof(double));

    int shape_filtre1[2] = {3,3};
    int dim_filtre1 = 2;
    double* filtre1 = (double*) malloc(shape_filtre1[0]*shape_filtre1[1] * sizeof(double));

    int* res = getResShape(shape_mat1, dim_mat1, shape_filtre1, dim_filtre1);
    int* shape_resultat = (int*) malloc(2*sizeof(int));
    shape_resultat[0] = res[0];
    shape_resultat[1] = res[1];
    printf("res %d %d \n", shape_resultat[0], shape_resultat[1]);
    int dim_resultat = res[2];
    double* resultat = (double*) malloc(shape_resultat[0]*shape_resultat[1] * sizeof(double));

    fillArray(mat1, shape_mat1, dim_mat1, 1);
    fillArray(filtre1, shape_filtre1, dim_filtre1, 0);

    printArray(mat1, shape_mat1, dim_mat1);
    printArray(filtre1, shape_filtre1, dim_filtre1);
    convolution2d(  mat1, shape_mat1, dim_mat1,
                    filtre1, shape_filtre1, dim_filtre1,
                    resultat, shape_resultat, dim_resultat);
    printf("\nmat1\n");
    printArray(mat1, shape_mat1, dim_mat1);
    printf("\nfiltre1\n");
    printArray(filtre1, shape_filtre1, dim_filtre1);
    printf("\nresultat\n");
    printArray(resultat, shape_resultat, dim_resultat);

    return 0;
}