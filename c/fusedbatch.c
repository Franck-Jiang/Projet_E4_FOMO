#include <stdio.h>
#include <math.h>
#include "array.h"


void normalization( double** input, int* input_shape, int input_dim, double mu, double sigma) {
    int totalsize = 1;
    for (int dim_i = 0; dim_i < input_dim; dim_i++){
        totalsize *= input_shape[dim_i];
    }

    for (int i = 0; i < totalsize; i++){
        (*input)[i] = ( (*input)[i] - mu ) / ( sigma + 0.00001 );
    }
}

int main(){ //ca marche testé et approuvé
    int dim = 2;
    int shape[2] = {3, 3};
    double val[3*3] = {3,2,1,7,8,9,5,5,5};

    double* array = initArray(shape, dim);
    printf("\nAvant: \n");
    setArray(&array, shape, dim, val);
    printArray(array, shape, dim);

    printf("\nApres: \n");
    normalization(&array, shape, dim, 2, 0.5);
    printArray(array, shape, dim);
}