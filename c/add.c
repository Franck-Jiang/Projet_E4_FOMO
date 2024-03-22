#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void add(   double* mat1, int* shape_mat1, int dim_mat1, 
            double* mat2, int* shape_mat2, int dim_mat2,
            double** resultat, int** shape_res, int* dim_res) {
    if ( dim_mat1 != dim_mat2 ) {
        for (int i = 0; i < dim_mat1; i++){
            if (shape_mat1[i] != shape_mat2[i]){
                printf("Erreur : Dimensions des matrices différentes\n");
            }
        }
    }
    else {
        *dim_res = dim_mat1;
        *shape_res = malloc( (*dim_res) * sizeof(int));
        int totalsize = 1;
        for (int dim_i = 0; dim_i < dim_mat1; dim_i++){
            (*shape_res)[dim_i] = shape_mat1[dim_i];
            totalsize *= shape_mat1[dim_i];
        }
        *resultat = (double*) malloc( (*shape_res)[0]* (*shape_res)[1] * sizeof(double));
        for (int i = 0; i < totalsize; i++){
            (*resultat)[i] = mat1[i] + mat2[i];
        }
    }

}

int main(void) {
    int dim_mat1 = 3;
    int shape_mat1[3] = {3, 3, 2};
    double* mat1 = initArray(shape_mat1, dim_mat1);
    fillArray(mat1, shape_mat1, dim_mat1, 0);


    int dim_mat2 = 3;
    int shape_mat2[3] = {3, 3, 2};
    double* mat2 = initArray(shape_mat2, dim_mat2);
    fillArray(mat2, shape_mat2, dim_mat2, 6);


    int dim_res;
    int *shape_res;
    double* resultat;


    add(mat1, shape_mat1, dim_mat1, 
        mat2, shape_mat2, dim_mat2,
        &resultat, &shape_res, &dim_res);

    for (int i = 0; i < dim_res; i++) printf("%d ", shape_res[i]);
    printf("\n");

    printf("\nmat1 :\n");
    printArray(mat1, shape_mat1, dim_mat1);
    printf("\nmat2 :\n");
    printArray(mat2, shape_mat2, dim_mat2);
    printf("\nres :\n");
    printArray(resultat, shape_res, dim_res);

    return 0;
}
