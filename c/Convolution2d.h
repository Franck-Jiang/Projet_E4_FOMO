#ifndef CONVOLUTION2D_H
#define CONVOLUTION2D_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h> 


int* getResShape(int* input_shape, int input_dim, int* filtre_shape, int filtre_dim);
void convolution2d(double* input, int* input_shape, int input_dim, 
                   double* filtre, int* filtre_shape, int filtre_dim, 
                   int stride_h, int stride_w,
                   double** resultat, int** resultat_shape, int* resultat_dim);

#endif  