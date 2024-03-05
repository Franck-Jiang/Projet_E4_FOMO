#include <stdio.h>
#include <math.h>

void softmax(double *input, int size) {
    double max = input[0];
    for (int i = 1; i < size; i++) {
        if (input[i] > max) {
            max = input[i];
        }
    }

    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        input[i] = exp(input[i] - max);
        sum += input[i];
    }

    for (int i = 0; i < size; i++) {
        input[i] /= sum;
    }
}

int main() {
    double input[] = {2.0, 1.0, 0.1};
    int size = sizeof(input) / sizeof(input[0]);

    softmax(input, size);

    printf("Softmax output: ");
    for (int i = 0; i < size; i++) {
        printf("%f ", input[i]);
    }
    printf("\n");

    return 0;
}