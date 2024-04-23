#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 

#include "quantification.h"
#include "array.h"
#include "Convolution2d.h"


 void fillFromFile(const char* filename, double* array, int* shape); 



// main

int main() {

    // definir image
    int shape[4] = {1, 96, 96, 1};
    double* image = initArray(shape, 4);
    fillArray(image, shape, 4, 0.0);
    
    // remplir l'image
    const char* filename = "input_data.txt";  

    fillFromFile(filename, image, shape);

    printArray(image, shape, 4);

    // quantization de l'image
    //int size = 1*96*96*1;
         //quantization ( image , input, size);

    
    
    // definir variable

    int shape_filtre[4] = {16, 3, 3, 1};
    int shape_output[4] = {1, 48, 48 ,16};

    double* filter = initArray (shape_filtre, 4);
    double* output = initArray ( shape_output , 4);

    //remplire filtre



    // conv 2D (1)
    //convolution2d( output, shape, 4,
                   //shape_filtre, shape_filtre, 4,
                   //2,2,
                   //output , shape_output, 4  );

    free(image);
    free(filter);
    free(output);

    return 0;
}



// fonction


 void fillFromFile(const char* filename, double* array, int* shape) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
         return;
    }

    int i, j, k, l;
    double value;
    while (fscanf(file, "%lf", &value) == 1) {
        // Supposons que le fichier contient les valeurs dans l'ordre approprié
        for (i = 0; i < shape[0]; i++) {
            for (j = 0; j < shape[1]; j++) {
                for (k = 0; k < shape[2]; k++) {
                    for (l = 0; l < shape[3]; l++) {
                        int index = i * (shape[1] * shape[2] * shape[3]) + j * (shape[2] * shape[3]) + k * shape[3] + l;
                        fscanf(file, "%lf", &array[index]);
                    }
                }
            }
        }
    }

    fclose(file);

}