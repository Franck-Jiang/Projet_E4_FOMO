#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"

matrice add(matrice mat1, matrice mat2) {
    if (mat1.m != mat2.m || mat1.n != mat2.n) {
        printf("Erreur : Dimensions des matrices différentes\n");
        return creer_matrice(1, 1);
    }

    int m = mat1.m;
    int n = mat1.n;
    matrice resultat = creer_matrice(m, n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            resultat.elem[i][j] = mat1.elem[i][j] + mat2.elem[i][j];
        }
    }

    return resultat;
}

int main(void) {
    matrice mat1 = creer_matrice1(5, 5);
    matrice mat2 = creer_matrice1(5, 5);

    matrice resultat = add(mat1, mat2);

    print_matrice(mat1);
    print_matrice(mat2);
    print_matrice(resultat);

    return 0;
}
