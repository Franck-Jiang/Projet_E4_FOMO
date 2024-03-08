#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "array.h"

int DEFAULT_DIM[2] = {1,1};

Array convolution2d(Array input, Array filtre) {

    if (input.ndim != 2 || filtre.ndim != 2){
        printf("Conv2D: need array2D\n");
        return initArray(DEFAULT_DIM, 2);
    }


    if (input.shape[0] < filtre.shape[0] || input.shape[1] < filtre.shape[1]) {
        printf("Erreur : Dimension filtre > Dimension input");
        return initArray(DEFAULT_DIM, 2);
    }

    int m = input.shape[0] - ceil( filtre.shape[0]/2.0 );
    int n = input.shape[1] - ceil( filtre.shape[1]/2.0 );

    int dim[2] = {m,n} ;
    Array resultat = initArray( dim, 2 );

    printf("Dimensions: %d, %d\n", m, n);
    // printf("OK\n");
    for (int i = 0; i < resultat.shape[0]; i++) {
        for (int j = 0; j < resultat.shape[1]; j++) {
            resultat.data.data2D[i][j] = 0;
            // printf("i=%d < %d, j=%d < %d\n", i, resultat.m, j, resultat.n);
            for (int k = 0; k < filtre.shape[0]; k++) {
                for (int l = 0; l < filtre.shape[1]; l++) {
                    // printf("i=%d, j=%d, k=%d, l=%d\n",i,j,k,l);
                    if (i + k < input.shape[1] && j + l < input.shape[1]){
                        resultat.data.data2D[i][j] += input.data.data2D[i + k][j + l] * filtre.data.data2D[k][l];
                        // printf("%f\n", resultat.elem[i][j]);
                    }
                }
            }
        }
    }

    return resultat;
}

int main(void){
    int dim1[2] = {5,5};
    Array mat1 = initArray(dim1, 2);

    int dim2[2] = {3,3};
    Array filtre1 = initArray(dim2, 2);

    fillArray(mat1, 1);
    fillArray(filtre1, 0);

    Array resultat = convolution2d(mat1, filtre1);
    printf("\nmat1\n");
    printData(mat1);
    printf("\nfiltre1\n");
    printData(filtre1);
    printf("\nresultat\n");
    printData(resultat);

    return 0;
}