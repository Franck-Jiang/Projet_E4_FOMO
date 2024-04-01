#include <stdio.h>
#include <stdlib.h>
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