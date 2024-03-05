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

//TODO 
float getValue(Array arr, int* position){
    printf("adr3 %p ", position);
    printf("size:%d ", sizeof(position)/sizeof(position[0]));
    size_t len = sizeof(position)/sizeof(position[0]);
    int position_array = 0;
    int a = 1;

    // for (int i = 0; i < len; i++){
    //     position_array += position[i]*a;
    //     a *= arr.shape[i];
    // }
    printf("(pos:%d)", position_array);
    return arr.data[position_array];
}

//TODO 
void setValue(Array arr, int* position, float value){
    int len = sizeof(position)/sizeof(int);
    int position_array = 0;
    for (int i = 0; i < len; i++){

    }
}


int main(void){
    int shape[] = {2,3,2};
    Array a = initArray(shape, 3);
    fillArray(a, 0);
    printData(a);
    freeArray(a);
    // int position[7] = {0,0,1};

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 2; k++){
                int pos[6] = {i,j,k,i,j,k};
                printf("adr1 %p ", pos);
                printf("size:%d ", sizeof(pos)/sizeof(pos[0]));
                printf("data[%d][%d][%d] = %.2f\n",i, j, k, getValue(a, pos));
            }
        }
    }
}

