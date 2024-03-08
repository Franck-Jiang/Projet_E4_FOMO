#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* shape;        // Tableau des dimensions
    int ndim;          // Nombre de dimensions
    float* data;        // Pointeur vers les données
} Array;

Array initArray(int* shape, int ndim) {
    Array arr;
    arr.shape = malloc(ndim * sizeof(int));
    arr.ndim = ndim;

    for (int i = 0; i < ndim; i++) {
        arr.shape[i] = shape[i];
    }

    int totalSize = 1;
    for (int i = 0; i < ndim; i++) {
        totalSize *= shape[i];
    }

    arr.data = malloc(totalSize * sizeof(float));

    return arr;
}

void freeArray(Array arr) {
    free(arr.shape);
    free(arr.data);
}

void fillArray(Array arr, float filler){
    int totalsize = 1;
    for (int shape_i=0; shape_i < arr.ndim; shape_i++){
        totalsize *= arr.shape[shape_i];
    }

    for (int i=0; i < totalsize; i++){
        arr.data[i] = filler+2*i;
    }
}

void printData(Array arr){
    int totalsize = 1;
    for (int i = 0; i < arr.ndim; i++){
        totalsize *= arr.shape[i];
    }
    for (int i = 0; i < totalsize; i++){
        printf("%.2f\t", arr.data[i]);
    }
    printf("\n");
}

float getValue(Array arr, int* position){

    int len = arr.ndim;
    int position_array = 0;
    int a = 1;

    for (int i = len - 1; i >= 0; i--){
        position_array += position[i]*a;
        a *= arr.shape[i];
    }
    // printf("(pos:%d)", position_array);
    return arr.data[position_array];
}

void setValue(Array arr, int* position, float value){
    int len = arr.ndim;
    int position_array = 0;
    int a = 1;

    for (int i = len - 1; i >= 0; i--){
        position_array += position[i]*a;
        a *= arr.shape[i];
    }
    // printf("(pos:%d)", position_array);
    arr.data[position_array] = value;
}


int main(void){
    int shape[] = {2,3,2};
    Array a = initArray(shape, 3);
    fillArray(a, 0);
    // printData(a);
    int pos[3] = {1,2,0};
    setValue(a, pos, 999);
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 2; k++){
                int pos[3] = {i,j,k};
                printf("data[%d][%d][%d] = %.2f\n",i, j, k, getValue(a, pos));
            }
        }
    }

    freeArray(a);
    printData(a);
}

