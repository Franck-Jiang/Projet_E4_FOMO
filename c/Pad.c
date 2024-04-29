#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void pad_array( double* input, int* input_shape, int input_dim, 
                int pad_top, int pad_bottom, int pad_left, int pad_right, 
                double pad_value, 
                double** output, int** output_shape, int* output_dim) {
    int height = input_shape[0];
    int width = input_shape[1];
    int padded_height = height + pad_top + pad_bottom;
    int padded_width = width + pad_left + pad_right;

    // Initialize the output array
    *output_shape = malloc(2 * sizeof(int));
    (*output_shape)[0] = padded_height;
    (*output_shape)[1] = padded_width;
    *output_dim = 2;
    int output_totalsize = padded_height * padded_width;
    *output = (double*) malloc(output_totalsize * sizeof(double));

    for (int i = 0; i < padded_height; i++) {
        for (int j = 0; j < padded_width; j++) {
            if (i < pad_top || i >= height + pad_top || j < pad_left || j >= width + pad_left) {
                (*output)[i * padded_width + j] = pad_value;
            } else {
                int original_row = i - pad_top;
                int original_col = j - pad_left;
                (*output)[i * padded_width + j] = input[original_row * width + original_col];
            }
        }
    }
}

int main() {
    int input_shape[2] = {3, 3};
    int input_dim = 2;
    double* input = (double*) malloc(input_shape[0]*input_shape[1] * sizeof(double)); 
    fillArray(input, input_shape, input_dim, 2);

    printf("Input Array:\n");
    printArray(input, input_shape, input_dim);

    int pad_top = 1;
    int pad_bottom = 1;
    int pad_left = 1;
    int pad_right = 1;
    double pad_value = 0.0;
    
    int* output_shape;
    int output_dim;
    double* output; 
    pad_array(  input, input_shape, input_dim,
                pad_top, pad_bottom, pad_left, pad_right, pad_value, 
                &output, &output_shape, &output_dim);

    printf("Output Array after padding:\n");
    printArray(output, output_shape, output_dim);

    return 0;
}
