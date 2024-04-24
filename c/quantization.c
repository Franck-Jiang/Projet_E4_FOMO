#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 
#include "array.h" 


void quantization(uint8_t* input, float* output, int* input_shape, int input_dim, float s, uint8_t off) {
    int totalsize = 1;
    for (int i = 0; i < input_dim; i++) {
        totalsize = input_shape[i];
    }

    for (int i = 0; i < totalsize; i++) {
        output[i] = s input[i] + off;

    }
}

int main() {
    int dim[1] = {3};
    uint8_t* input = malloc(3 * sizeof(uint8_t)); // Allouer de la mémoire pour l'entrée
    // Remplir l'entrée avec des valeurs initiales (par exemple, des valeurs de pixel)
    fillArray(input, dim, 1, (uint8_t)1);

    printf("Input: ");
    printArray(input, dim, 1);

    // Appel de la fonction quantization avec les paramètres spécifiés
    float* output = malloc(3 * sizeof(float)); // Allouer de la mémoire pour la sortie
    quantization(input, output, dim, 1, 0.00390625, 128); 

    printf("Output after quantization: ");
    for (int i = 0; i < 3; i++) {
        printf("%f ", output[i]);
    }
    printf("\n");

    free(input); // Libérer la mémoire allouée pour l'entrée
    free(output); // Libérer la mémoire allouée pour la sortie

    return 0;
}
