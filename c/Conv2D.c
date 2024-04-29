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
        printf("a %d\n", filtre_shape[1]);
        printf("b %f\n", filtre_shape[1]/2.0);
        printf("c %f\n", ceil(filtre_shape[1]/2.0));
        printf("getres %d %d ", resultat[0], resultat[1]);
    }
    return resultat;
    }

void convolution2d( double* input, int* input_shape, int input_dim, 
                    double* filtre, int* filtre_shape, int filtre_dim, 
                    int stride_h, int stride_w,
                    double** resultat, int** resultat_shape, int* resultat_dim ) {

    if (input_dim != 2 || filtre_dim != 2) {
        printf("Convolution erreur dim\n");
    }
    else {
        *resultat_dim = input_dim;
        *resultat_shape = (int*) malloc( (*resultat_dim) * sizeof(int) );
        
        // Calcul de la taille de la sortie en fonction du stride
        (*resultat_shape)[0] = (input_shape[0] - filtre_shape[0]) / stride_h + 1;
        (*resultat_shape)[1] = (input_shape[1] - filtre_shape[1]) / stride_w + 1;
        *resultat = initArray(*resultat_shape, *resultat_dim);

        printf("Dimensions: %d, %d\n", (*resultat_shape)[0], (*resultat_shape)[1]);
        for (int i = 0; i < (*resultat_shape)[0]; i++) {
            for (int j = 0; j < (*resultat_shape)[1]; j++) {
                (*resultat)[i*(*resultat_shape)[0] + j] = 0;
                for (int k = 0; k < filtre_shape[0]; k++) {
                    for (int l = 0; l < filtre_shape[1]; l++) {
                        int input_row = i * stride_h + k;
                        int input_col = j * stride_w + l;
                        
                        if (input_row >= 0 && input_row < input_shape[0] && 
                            input_col >= 0 && input_col < input_shape[1]) {
                            
                            (*resultat)[i * (*resultat_shape)[1] + j] += input[input_row * input_shape[1] + input_col] * filtre[k * filtre_shape[1] + l];
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

    double* resultat;
    int* shape_resultat;
    int dim_resultat;

    fillArray(mat1, shape_mat1, dim_mat1, 1);
    fillArray(filtre1, shape_filtre1, dim_filtre1, 0);

    // printArray(mat1, shape_mat1, dim_mat1);
    // printArray(filtre1, shape_filtre1, dim_filtre1);

    convolution2d(  mat1, shape_mat1, dim_mat1,
                    filtre1, shape_filtre1, dim_filtre1, 
                    1, 1,
                    &resultat, &shape_resultat, &dim_resultat);

    printf("\nmat1\n");
    printArray(mat1, shape_mat1, dim_mat1);
    printf("\nfiltre1\n");
    printArray(filtre1, shape_filtre1, dim_filtre1);
    printf("\nresultat\n");
    printArray(resultat, shape_resultat, dim_resultat);

    return 0;
}
