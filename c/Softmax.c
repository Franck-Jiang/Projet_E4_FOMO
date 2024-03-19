#include <stdio.h>
#include <math.h>
#include "array.h"

void softmax(double* input, int* input_shape, int input_dim) {
    int totalsize = 1;
    for (int i = 0; i < input_dim; i++){
        totalsize *= input_shape[i];
    }

    double max = input[0];
    for (int i = 1; i < totalsize; i++) {
        if (input[i] > max) {
            max = input[i];
        }
    }

    double sum = 0.0;
    for (int i = 0; i < totalsize; i++) {
        input[i] = exp(input[i] - max);
        sum += input[i];
    }

    for (int i = 0; i < totalsize; i++) {
        input[i] /= sum;
    }
}

int main() {
    int dim[1] = {3};
    double* input = (double*) malloc(dim[0]*sizeof(double));
    fillArray(input, dim, 1, 1);


    printf("Input: ");
    printArray(input, dim, 1);

    printf("\n");
    softmax(input, dim, 1);

    printf("Softmax output: ");
    printArray(input, dim, 1);
    printf("\n");

    return 0;
}