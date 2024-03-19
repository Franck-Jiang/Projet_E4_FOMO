#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"


                    



Array deepconvolution(Array input_data, Array kernel, int* stride) {
    int input_height = input_data.shape[0];
    int input_width = input_data.shape[1];
    int input_channels = input_data.shape[2];
    int num_examples = input_data.shape[3];
    
    int kernel_height = kernel.shape[0];
    int kernel_width = kernel.shape[1];
    int kernel_channels = kernel.shape[2];
    
    int output_height = (input_height - kernel_height) / stride[0] + 1;
    int output_width = (input_width - kernel_width) / stride[1] + 1;
    int output_channels = kernel_channels;
    
    // Initialisation du tableau de sortie
    int output_shape[] = {output_height, output_width, output_channels, num_examples};
    Array output = initArray(output_shape, 4);
    
    // Parcours de chaque exemple dans le batch
    for (int ex = 0; ex < num_examples; ex++) {
        // Parcours de l'image avec le stride spécifié
        for (int i = 0; i < output_height; i++) {
            for (int j = 0; j < output_width; j++) {
                // Parcours des canaux du noyau
                for (int k = 0; k < output_channels; k++) {
                    double sum = 0.0;
                    // Convolution sur une fenêtre de la matrice d'entrée avec le noyau
                    for (int x = 0; x < kernel_height; x++) {
                        for (int y = 0; y < kernel_width; y++) {
                            for (int z = 0; z < input_channels; z++) {
                                sum += input_data.data[((i * stride[0] + x) * input_width + (j * stride[1] + y)) * input_channels + z + ex * input_height * input_width * input_channels] *
                                       kernel.data[(x * kernel_width + y) * kernel_channels + z + k * kernel_height * kernel_width * kernel_channels];
                            }
                        }
                    }
                    // Stockage du résultat dans le tableau de sortie
                    output.data[((i * output_width + j) * output_channels + k) * num_examples + ex] = sum;
                }
            }
        }
    }
    return output;
}


int main() {
    // Exemple d'utilisation de la fonction deepconvolution
    int input_shape[] = {1, 5, 3, 2}; // Taille de l'image d'entrée (5x5x3) avec 2 exemples dans le batch
    Array input_data = initArray(input_shape, 4);
    fillArray(input_data, 1.0); // Remplissage avec des valeurs arbitraires pour l'exemple
    
    int kernel_shape[] = {1, 3, 3, 3}; // Taille du noyau de convolution (3x3x3) avec 3 canaux
    Array kernel = initArray(kernel_shape, 4);
    fillArray(kernel, 0.5); // Remplissage avec des valeurs arbitraires pour l'exemple
    
    int stride[] = {1, 1}; // Stride (pas de décalage) en hauteur et en largeur
    
    // Appel de la fonction de convolution profonde
    Array output = deepconvolution(input_data, kernel, stride);
   
    // Affichage des données de sortie
    printData(output);
   


    // Libération de la mémoire allouée pour les tableaux
    free(input_data.shape);
    free(input_data.data);
    free(kernel.shape);
    free(kernel.data);
    free(output.shape);
    free(output.data);
    
    return 0;
}
