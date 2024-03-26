#include <stdio.h>
#include <math.h>
#include "array.h"

void relu6(double** input, int* input_shape, int input_dim) {
    int totalsize = 1;
    for (int i = 0; i < input_dim; i++) {
        totalsize *= input_shape[i];
    }

    for (int i = 0; i < totalsize; i++) {
        if ((*input)[i] < 0) {
            (*input)[i] = 0;
        } else if ((*input)[i] > 6) {
            (*input)[i] = 6;
        }
    }
}

int main() {
    int dim[1] = {3};
    double* input = initArray(dim, 1);
    fillArray(input, dim, 1, 1);

    printf("Input: ");
    printArray(input, dim, 1);

    printf("\n");
    relu6(&input, dim, 1);

    printf("ReLU6 output: ");
    printArray(input, dim, 1);
    printf("\n");

    return 0;
}
