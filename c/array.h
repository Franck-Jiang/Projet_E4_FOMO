#ifndef ARRAY_H
#define ARRAY_H
#include "array.c"

struct Array;

// Initialiser un tableau
Array initArray(int* shape, int ndim);

// Libérer la mémoire du tableau
void freeArray(Array arr);

// Remplir le tableau avec une valeur
void fillArray(Array arr, float filler);

// Afficher les données du tableau
void printData(Array arr);

// Obtenir la valeur à une position donnée dans le tableau
float getValue(Array arr, int* position);

// Définir la valeur à une position donnée dans le tableau
void setValue(Array arr, int* position, float value);

#endif  // ARRAY_H
