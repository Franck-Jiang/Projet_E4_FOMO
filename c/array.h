#ifndef ARRAY_H
#define ARRAY_H
#include "array.c"

struct Array;

// Initialiser un tableau
void fillArray( double* arr, int* shape, int dim, double filler);
void printArray( double* arr, int* shape, int dim );


#endif  // ARRAY_H
