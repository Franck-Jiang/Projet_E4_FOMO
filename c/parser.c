#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

#define MAX_LINE_LENGTH 1000

double* readDoubleList(char* string){
    int num_commas = 0;
    char* c = string;
    while (*c != '\0') {
        if (*c == ',') {
            num_commas++;
        }
        c++;
    }

    int size = num_commas + 1;

    double* array = (double*) malloc(size * sizeof(double));

    // Analyser la chaîne pour extraire les dimensions
    char* token = strtok((char*) string, ",");
    int i = 0;
    while (token != NULL) {
        // printf("token[%d] = %lf\n", i, atof(token));
        array[i] = atof(token);
        i++;
        token = strtok(NULL, ",");
    }

    return array;
}

int* readIntList(char* string){
    int num_commas = 0;
    char* c = string;
    while (*c != '\0') {
        if (*c == ',') {
            num_commas++;
        }
        c++;
    }

    int size = num_commas + 1;

    int* array = (int*) malloc(size * sizeof(int));

    // Analyser la chaîne pour extraire les dimensions
    char* token = strtok((char*) string, ",");
    int i = 0;
    while (token != NULL) {
        // printf("token[%d] = %lf\n", i, atof(token));
        array[i] = atoi(token);
        i++;
        token = strtok(NULL, ",");
    }

    return array;
}

void readArray(char* string, double** array, int** array_shape, int* array_dim){

    char name[MAX_LINE_LENGTH];
    char data[MAX_LINE_LENGTH];
    char shape[MAX_LINE_LENGTH];

    // char* name;
    // double* data;
    // int* shape;
    int dim;

    // Utilisation de sscanf pour extraire les différentes parties de la ligne
    if (sscanf(string, "%[^;];%[^;];%[^;];%d", name, data, shape, &dim) == 4) {
        printf("Name = %s\n", name);
        printf("Data = %s\n", data);
        printf("Shape = %s\n", shape);
        printf("Dim = %d\n", dim);
    } else {
        printf("Format de ligne incorrect.\n");
    }

    int* shape_array = readIntList(shape);
    double* data_array = readDoubleList(data);
    double* arr = initArray(shape_array, dim);
    setArray(&arr, shape_array, dim, data_array);
    
    (*array) = arr;
    (*array_shape) = shape_array;
    (*array_dim) = dim;
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];

    // Ouvrir le fichier en mode lecture
    file = fopen("test.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Impossible d'ouvrir le fichier.\n");
        exit(EXIT_FAILURE);
    }

    // Lire chaque ligne du fichier
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        // Traitement de chaque ligne ici
        printf("%s", line);

        int* shape;
        int dim;
        double* array;

        readArray(line, &array, &shape, &dim);
        printArray(array, shape, dim);
        printf("\n");
    }

    // Fermer le fichier
    fclose(file);
    return 0;
}