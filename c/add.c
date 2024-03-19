#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void add(   double* mat1, int* shape_mat1, int dim_mat1, 
            double* mat2, int* shape_mat2, int dim_mat2,
            double* resultat, int* shape_res, int dim_res) {
    if ( dim_mat1 != dim_mat2 ) {
        for (int i = 0; i < dim_mat1; i++){
            if (shape_mat1[i] != shape_mat2[i]){
                printf("Erreur : Dimensions des matrices différentes\n");
            }
        }
    }
    else {
        for (int i = 0; i < shape_mat1[0]; i++) {
            for (int j = 0; j < shape_mat1[1]; j++) {
                resultat[i*shape_mat1[1] + j] = mat1[i*shape_mat1[1] +j] + mat2[i*shape_mat1[1] +j];
                printf("%.2f\n", resultat[i*shape_mat1[1] + j]);
            }
        }
    }

}

int main(void) {
    int dim_mat1 = 2;
    int shape_mat1[2] = {5, 5};
    double* mat1 = (double*) malloc(shape_mat1[0]*shape_mat1[1] * sizeof(double));
    fillArray(mat1, shape_mat1, dim_mat1, 0);


    int dim_mat2 = 2;
    int shape_mat2[2] = {5, 5};
    double* mat2 = (double*) malloc(shape_mat2[0]*shape_mat2[1] * sizeof(double));
    fillArray(mat2, shape_mat2, dim_mat2, 6);


    int dim_res = 2;
    int shape_res[2] = {5, 5};
    double* resultat = (double*) malloc(shape_res[0]*shape_res[1] * sizeof(double));

    add(mat1, shape_mat1, dim_mat1, 
        mat2, shape_mat2, dim_mat2,
        resultat, shape_res, dim_res);
    
    printf("mat1 : \n\n");
    printArray(mat1, shape_mat1, dim_mat1);
    printf("mat2 : \n\n");
    printArray(mat2, shape_mat2, dim_mat2);
    printf("res : \n\n");
    printArray(resultat, shape_res, dim_res);

    return 0;
}
