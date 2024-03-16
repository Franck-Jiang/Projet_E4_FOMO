#include <stdio.h>
#include <math.h>
#include "array.h"

void softmax(Array input) {
    double max = input.data[0];
    for (int i = 1; i < input.totalsize; i++) {
        if (input.data[i] > max) {
            max = input.data[i];
        }
    }

    double sum = 0.0;
    for (int i = 0; i < input.totalsize; i++) {
        input.data[i] = exp(input.data[i] - max);
        sum += input.data[i];
    }

    for (int i = 0; i < input.totalsize; i++) {
        input.data[i] /= sum;
    }
}

int main() {
    int dim[1] = {3};
    Array input = initArray(dim, 1);
    fillArray(input, 0);

    printf("Input: ");
    for (int i = 0; i < input.totalsize; i++) {
        printf("%f ", input.data[i]);
    }
    printf("\n");
    softmax(input);

    printf("Softmax output: ");
    for (int i = 0; i < input.totalsize; i++) {
        printf("%f ", input.data[i]);
    }
    printf("\n");

    return 0;
}