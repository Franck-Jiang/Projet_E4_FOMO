#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* shape;        // Tableau des dimensions
    int ndim;          // Nombre de dimensions
    int totalsize;
    float* data;        // Pointeur vers les données
} Array;

Array initArray(int* shape, int ndim) {
    Array arr;
    arr.shape = malloc(ndim * sizeof(int));
    for (int i = 0; i < ndim; i++) {
        arr.shape[i] = shape[i];
    }    
    arr.ndim = ndim;
    
    int totalSize = 1;
    for (int i = 0; i < ndim; i++) {
        totalSize *= shape[i];
    }
    arr.totalsize = totalSize;
    arr.data = (float*) malloc(totalSize * sizeof(float));
    return arr;
}

void printData(Array arr){
    if (arr.ndim == 2){
        for (int i = 0; i < arr.shape[0]; i++){
            for (int j = 0; j < arr.shape[1]; j++){
                printf("%.2f\t", arr.data[i* arr.shape[0] + j]);
            }
            printf("\n");
        }
    }
    else{
        printf("Data:\n");
        for (int i = 0; i < arr.totalsize; i++) {
            printf("%.2f ", arr.data[i]);
        }
        printf("\n");
    }

}


void fillArray(Array arr, float filler){
    for (int i = 0; i < arr.totalsize; i++){
        arr.data[i] = filler + i;
    }
}


