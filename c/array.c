#include <stdio.h>
#include <stdlib.h>

void fillArray( double* arr, int* shape, int dim, double filler){
    int totalsize = 1;
    for( int dim_i = 0; dim_i < dim; dim_i++ ){
        totalsize *= shape[dim_i];
    }

    for ( int i = 0; i < totalsize; i++) {
        arr[i] = filler + i;
    }
}

void printArray( double* arr, int* shape, int dim ){
    if (dim == 2){
        for (int i = 0; i < shape[0]; i++){
            for (int j = 0; j < shape[1]; j++){
                printf("%.2f\t", arr[i* shape[1] + j]);
                // printf("%d", i* shape[0] + j);
            }
            printf("\n");
        }
    }
    else{
        int totalsize = 1;
        for( int dim_i = 0; dim_i < dim; dim_i++ ){
        totalsize *= shape[dim_i];
        }
        printf("Data:\n");
        for (int i = 0; i < totalsize; i++) {
            printf("%.2f ", arr[i]);
        }
        printf("\n");
    }

}



