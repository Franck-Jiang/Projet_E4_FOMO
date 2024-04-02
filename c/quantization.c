#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> // Pour uint8_t
#include "array.h" // Inclure le fichier d'en-tête contenant les déclarations des fonctions

void toUint8(double* input, uint8_t* output, int size) {
    for (int i = 0; i < size; i++) {
        double value = input[i];
        // Arrondir la valeur à l'entier le plus proche
        if (value < 0) value = 0; // Assurer que la valeur n'est pas négative
        if (value > 255) value = 255; // Assurer que la valeur ne dépasse pas 255
        output[i] = (uint8_t)(value + 0.5); // Arrondi au plus proche entier
    }
}

int main() {
    int dim[1] = {3};
    double* input = initArray(dim, 1);
    fillArray(input, dim, 1, 1);

    printf("Input: ");
    printArray(input, dim, 1);

    // Appel de la fonction toUint8
    uint8_t* output = malloc(3 * sizeof(uint8_t)); // Allouer de la mémoire pour le tableau de sortie
    toUint8(input, output, 3); // Appeler la fonction de quantification

    printf("Output after quantification: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");

    // Libérer la mémoire allouée pour le tableau de sortie
    free(output);

    return 0;