#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct{
    float** elem;
    int m; 
    int n;
}matrice;

matrice creer_matrice(int m, int n){
    matrice mat;
    mat.m=m;
    mat.n=n;
    mat.elem = (float**)malloc( m*sizeof(float*) );
    for ( int i=0; i<m; i++){
        mat.elem[i] = (float*)malloc( n*sizeof(float) );
    }

    float count = 0.651;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            mat.elem[i][j] = count*i*j+i+j;
        }
    }
    return mat;
}

matrice creer_matrice1(int m, int n){
    matrice mat;
    mat.m=m;
    mat.n=n;
    mat.elem = (float**)malloc( m*sizeof(float*) );
    for ( int i=0; i<m; i++){
        mat.elem[i] = (float*)malloc( n*sizeof(float) );
    }

    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            mat.elem[i][j] = 1;
        }
    }
    return mat;
}

matrice creer_filtre(int m, int n){
    matrice mat;
    mat.m=m;
    mat.n=n;
    mat.elem = (float**)malloc( m*sizeof(float*) );
    for ( int i=0; i<m; i++){
        mat.elem[i] = (float*)malloc( n*sizeof(float) );
    }

    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            mat.elem[i][j] = 1*(i^j);
        }
    }
    return mat;
}

void print_matrice(matrice mat){

    int m = mat.m;
    int n = mat.n;
    printf("m=%d, n=%d\n", m, n);
    for (int i=0; i < m; i++){
        for (int j=0; j < n; j++){
            printf("%.3f\t", mat.elem[i][j]);
        }
        printf("\n");
    }
}