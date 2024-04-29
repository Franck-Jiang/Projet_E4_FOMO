#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"


                    



void deepconvolution(   double* input, int* input_shape, int input_dim,
                        double* kernel,int* kernel_shape, int kernel_dim,
                        double** output, int** output_shape, int* output_dim,
                        int* stride) {
    int input_height = input_shape[0];
    int input_width = input_shape[1];
    int input_channels = input_shape[2];
    int num_examples = input_shape[3];
    
    int kernel_height = kernel_shape[0];
    int kernel_width = kernel_shape[1];
    int kernel_channels = kernel_shape[2];
    
    int output_height = (input_height - kernel_height) / stride[0] + 1;
    int output_width = (input_width - kernel_width) / stride[1] + 1;
    int output_channels = kernel_channels;
    
    // Initialisation du tableau de sortie
    *output_dim = 4;
    *output_shape = (int*) malloc( (*output_dim) * sizeof(int));
    (*output_shape)[0] = output_height;
    (*output_shape)[1] = output_width;
    (*output_shape)[2] = output_channels;
    (*output_shape)[3] = num_examples;
    *output = initArray(*output_shape, 4);
    
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
                                sum += input[((i * stride[0] + x) * input_width + (j * stride[1] + y)) * input_channels + z + ex * input_height * input_width * input_channels] *
                                       kernel[(x * kernel_width + y) * kernel_channels + z + k * kernel_height * kernel_width * kernel_channels];
                            }
                        }
                    }
                    // Stockage du résultat dans le tableau de sortie
                    (*output)[((i * output_width + j) * output_channels + k) * num_examples + ex] = sum;
                }
            }
        }
    }
}


int main() {
    // Exemple d'utilisation de la fonction deepconvolution
    int input_shape[] = {1, 5, 3, 2}; // Taille de l'image d'entrée (5x5x3) avec 2 exemples dans le batch
    double* input_data = initArray(input_shape, 4);
    fillArray(input_data, input_shape, 4, 1.0); // Remplissage avec des valeurs arbitraires pour l'exemple
    
    int kernel_shape[] = {1, 3, 3, 3}; // Taille du noyau de convolution (3x3x3) avec 3 canaux
    double* kernel = initArray(kernel_shape, 4);
    fillArray(kernel, kernel_shape, 4, 0.5); // Remplissage avec des valeurs arbitraires pour l'exemple
    
    int stride[] = {1, 1}; // Stride (pas de décalage) en hauteur et en largeur
    
    // Appel de la fonction de convolution profonde
    int output_dim;
    int* output_shape;
    double* output;
    deepconvolution(input_data, input_shape, 4,
                    kernel, kernel_shape, 4,
                    &output, &output_shape, &output_dim,
                    stride);
   
    // Affichage des données de sortie
    printArray(output, output_shape, output_dim);
   


    // Libération de la mémoire allouée pour les tableaux
    free(input_data);
    free(kernel);
    free(output_shape);
    free(output);
    
    return 0;
}
