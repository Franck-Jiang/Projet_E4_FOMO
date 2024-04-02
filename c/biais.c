#include <stdio.h>
#include <math.h>
#include "array.h"

void add_bias(double** input, int* input_shape, int input_dim, double bias) {
    int totalsize = 1;
    for (int i = 0; i < input_dim; i++) {
        totalsize *= input_shape[i];
    }

    for (int i = 0; i < totalsize; i++) {
        (*input)[i] += bias;
    }
}

int main() {
    int dim[1] = {3};
    double* input = initArray(dim, 1);
    fillArray(input, dim, 1, 1);

    printf("Input: ");
    printArray(input, dim, 1);

    double bias = 0.5; // Biais Ã  ajouter
    printf("\nAdding bias: %lf\n", bias);
    add_bias(&input, dim, 1, bias);

    printf("Output after adding bias: ");
    printArray(input, dim, 1);
    printf("\n");

    return 0;
}
