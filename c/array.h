#ifndef ARRAY_H
#define ARRAY_H
#include "array.c"

struct Array;

// Initialiser un tableau
Array initArray(int* shape, int ndim);

void printData(Array arr);

void fillArray(Array arr, double filler);

#endif  // ARRAY_H
