#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"


                    






Array deepConvolution(Array input, Array kernel) {
    if (input.ndim != 4 || kernel.ndim != 4) {
        printf("Les entrées doivent être des matrices 4D.\n");
        // Retourner une matrice vide ou une erreur selon votre besoin
    }

    int output_shape[4];
    output_shape[0] = input.shape[0];  // Garde la même taille en batch
    output_shape[1] = input.shape[1] - kernel.shape[1] + 1;  // La taille en hauteur de l'image de sortie
    output_shape[2] = input.shape[2] - kernel.shape[2] + 1;  // La taille en largeur de l'image de sortie
    output_shape[3] = kernel.shape[3];  // Le nombre de canaux de l'image de sortie

    Array output = initArray(output_shape, 4);

    // Appliquer la convolution
    for (int b = 0; b < input.shape[0]; b++) {  // Pour chaque batch
        for (int i = 0; i < output.shape[1]; i++) {  // Parcours en hauteur
            for (int j = 0; j < output.shape[2]; j++) {  // Parcours en largeur
                for (int c = 0; c < output.shape[3]; c++) {  // Pour chaque canal
                    float sum = 0.0;
                    for (int di = 0; di < kernel.shape[1]; di++) {  // Parcours du noyau en hauteur
                        for (int dj = 0; dj < kernel.shape[2]; dj++) {  // Parcours du noyau en largeur
                            for (int dk = 0; dk < kernel.shape[3]; dk++) {  // Parcours des canaux du noyau
                                sum += input.data.data4D[b][i + di][j + dj][dk] * kernel.data.data4D[0][di][dj][dk];
                            }
                        }
                    }
                    output.data.data4D[b][i][j][c] = sum;
                }
            }
        }
    }
    
    return output;
}

int main() {
    // Définition des dimensions des matrices
    int input_shape[] = {1, 5, 5, 3}; // Input : 1 batch de taille 5x5 avec 3 canaux
    int kernel_shape[] = {1, 3, 3, 3}; // Noyau : 1 noyau de taille 3x3 avec 3 canaux

    // Initialisation des matrices
    Array input = initArray(input_shape, 4);
    Array kernel = initArray(kernel_shape, 4);

    // Remplissage des matrices (pour l'exemple, on les remplit avec des valeurs aléatoires)
    fillArray(input, 1.0); // Remplit la matrice input avec des valeurs de 1.0
    fillArray(kernel, 0.5); // Remplit la matrice kernel avec des valeurs de 0.5

    // Application de la convolution profonde
    Array output = deepConvolution(input, kernel);

    // Affichage des résultats (pour l'exemple, on affiche juste les dimensions de la matrice de sortie)
    printf("Dimensions de la matrice de sortie : %d x %d x %d x %d\n", 
           output.shape[0], output.shape[1], output.shape[2], output.shape[3]);

    // Libération de la mémoire allouée pour les matrices
    freeArray(input);
    freeArray(kernel);
    freeArray(output);

    return 0;
}
