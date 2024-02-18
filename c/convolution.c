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

matrice convolution(matrice input, matrice filtre) {


    if (input.m < filtre.m || input.n < filtre.n) {
        printf("Erreur : Dimension filtre > Dimension input");
        return creer_matrice(1, 1);
    }

    int m = input.m - ceil( filtre.m/2.0 );
    int n = input.n - ceil( filtre.n/2.0 );
    matrice resultat = creer_matrice(m,n);

    printf("Dimensions: %d, %d\n", m, n);
    // printf("OK\n");
    for (int i = 0; i < resultat.m; i++) {
        for (int j = 0; j < resultat.n; j++) {
            resultat.elem[i][j] = 0;
            // printf("i=%d < %d, j=%d < %d\n", i, resultat.m, j, resultat.n);
            for (int k = 0; k < filtre.m; k++) {
                for (int l = 0; l < filtre.n; l++) {
                    // printf("i=%d, j=%d, k=%d, l=%d\n",i,j,k,l);
                    if (i + k < input.m && j + l < input.n){
                        resultat.elem[i][j] += input.elem[i + k][j + l] * filtre.elem[k][l];
                        // printf("%f\n", resultat.elem[i][j]);
                    }
                }
            }
        }
    }

    return resultat;
}

int main(void){
    matrice mat1 = creer_matrice1(5,5);
    matrice filtre1 = creer_filtre(3,3);

    matrice resultat = convolution(mat1, filtre1);

    print_matrice(mat1);
    print_matrice(filtre1);
    print_matrice(resultat);

    return 0;
}