#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* shape;        // Tableau des dimensions
    int ndim;          // Nombre de dimensions
    int totalsize;
    union{
        float** data2D;
        float*** data3D;
        float**** data4D;
    } data;        // Pointeur vers les données
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

    if (ndim == 2){
        arr.data.data2D = (float**) malloc(arr.shape[0] * sizeof(float*));
        for (int i = 0; i < arr.shape[0]; i++){
                arr.data.data2D[i] = (float*) malloc(arr.shape[1] * sizeof(float));
            }
    }
    else if (ndim == 3){
        arr.data.data3D = (float***) malloc(arr.shape[0] * sizeof(float**));
        for (int i = 0; i < arr.shape[0]; i++){
            arr.data.data3D[i] = (float**) malloc(arr.shape[1] * sizeof(float*));
            for (int j = 0; j < arr.shape[1]; j++){
                arr.data.data3D[i][j] = (float*) malloc(arr.shape[1] * sizeof(float));
            }
        }
    }
    else if (arr.ndim == 4) {
        arr.data.data4D = (float****)malloc(arr.shape[0] * sizeof(float***));
        for (int i = 0; i < arr.shape[0]; i++) {
            arr.data.data4D[i] = (float***)malloc(arr.shape[1] * sizeof(float**));
            for (int j = 0; j < arr.shape[1]; j++) {
                arr.data.data4D[i][j] = (float**)malloc(arr.shape[2] * sizeof(float*));
                for (int k = 0; k < arr.shape[2]; k++) {
                    arr.data.data4D[i][j][k] = (float*)malloc(arr.shape[3] * sizeof(float));
                }
            }
        }
    }
    else{
        printf("Ndim incorrecte (valeurs possible : 2-4)\n");
        return arr; 
    }
    // printf("init ok \n");
    return arr;
}

void freeArray(Array arr) {
    free(arr.shape);
    free(arr.data.data2D);
    free(arr.data.data3D);
    free(arr.data.data4D);
}

void fillArray(Array arr, float filler){
    int totalsize = arr.totalsize;

    if (arr.ndim == 2){
        for (int i=0; i < arr.shape[0]; i++){
            for (int j = 0; j < arr.shape[1]; j++){
                arr.data.data2D[i][j] = filler+i+j;
            }
        }
    }
    else if (arr.ndim == 3){
        for (int i=0; i < arr.shape[0]; i++){
            for (int j = 0; j < arr.shape[1]; j++){
                for (int k = 0; k < arr.shape[2]; k++){
                    arr.data.data3D[i][j][k] = filler+i+j+k;
                }
            }
        }
    }
    else if(arr.ndim == 4) {
        for (int i=0; i < arr.shape[0]; i++){
            for (int j = 0; j < arr.shape[1]; j++){
                for (int k = 0; k < arr.shape[2]; k++){
                    for (int l = 0; l < arr.shape[3]; l++){
                        arr.data.data4D[i][j][k][l] = filler+i+j+k+l;
                    }
                }
            }
        }
    }
    // printf("fill OK\n");
}

void printData(Array arr){
    int totalsize = arr.totalsize;
    if (arr.ndim == 2){
        for (int i=0; i < arr.shape[0]; i++){
            for (int j = 0; j < arr.shape[1]; j++){
                printf("data[%d][%d]=%.2f\n", i, j, arr.data.data2D[i][j]);
            }
        }
    }
    else if (arr.ndim == 3){
        for (int i=0; i < arr.shape[0]; i++){
            for (int j = 0; j < arr.shape[1]; j++){
                for (int k = 0; k < arr.shape[2]; k++){
                    printf("data[%d][%d][%d]=%.2f\n", i, j, k, arr.data.data3D[i][j][k]);
                }
            }
        }
    }
    else {
        for (int i=0; i < arr.shape[0]; i++){
            for (int j = 0; j < arr.shape[1]; j++){
                for (int k = 0; k < arr.shape[2]; k++){
                    for (int l = 0; l < arr.shape[3]; l++){
                        printf("data[%d][%d][%d][%d]=%.2f\n", i, j, k, l, arr.data.data4D[i][j][k][l]);
                    }
                }
            }
        }
    }
}




// int main(void){
//     int shape[] = {2,3,2};
//     Array a = initArray(shape, 3);
//     fillArray(a, 10);
//     printData(a);
//     // printf("data : %d", a.data.data3D[1][0][1]);

//     freeArray(a);
//     printData(a);
// }

