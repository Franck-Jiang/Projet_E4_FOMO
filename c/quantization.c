#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 
#include "array.h" 

void quantization(double* input, uint8_t* output, int size, double factor, double bias) {
    for (int i = 0; i < size; i++) {
        double value = factor * (input[i] + bias);
        output[i] = (uint8_t)(value);
    }
}

int main() {
    int dim[1] = {3};
    double* input = initArray(dim, 1);
    fillArray(input, dim, 1, 1);

    printf("Input: ");
    printArray(input, dim, 1);

    // Appel de la fonction quantization avec les paramètres spécifiés
    uint8_t* output = malloc(3 * sizeof(uint8_t)); 
    quantization(input, output, 3, 0.00390625, 128); 

    printf("Output after quantization: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");

    free(output); // Libérer la mémoire allouée pour le tableau de sortie

    return 0;
}
