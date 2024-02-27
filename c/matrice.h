#ifndef MATRICE_H
#define MATRICE_H

#include "matrice.c"

struct matrice;

matrice creer_matrice(int m, int n);
matrice creer_matrice1(int m, int n);
matrice creer_filtre(int m, int n);
void print_matrice(matrice mat);

#endif