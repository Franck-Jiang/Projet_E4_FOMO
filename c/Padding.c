#include <stdio.h>
#include <stdlib.h>
#include "array.c"

void pad_array(Array input, int pad_top, int pad_bottom, int pad_left, int pad_right, double pad_value, Array* output) {
    int height = input.shape[0];
    int width = input.shape[1];
    int padded_height = height + pad_top + pad_bottom;
    int padded_width = width + pad_left + pad_right;

    // Initialize the output array
    output->shape = malloc(2 * sizeof(int));
    output->shape[0] = padded_height;
    output->shape[1] = padded_width;
    output->ndim = 2;
    output->totalsize = padded_height * padded_width;
    output->data = (double*) malloc(output->totalsize * sizeof(double));

    for (int i = 0; i < padded_height; i++) {
        for (int j = 0; j < padded_width; j++) {
            if (i < pad_top || i >= height + pad_top || j < pad_left || j >= width + pad_left) {
                output->data[i * padded_width + j] = pad_value;
            } else {
                int original_row = i - pad_top;
                int original_col = j - pad_left;
                output->data[i * padded_width + j] = input.data[original_row * width + original_col];
            }
        }
    }
}

int main() {
    int shape[2] = {3, 3};
    Array input = initArray(shape, 2);
    fillArray(input, 1.0);
    
    printf("Input Array:\n");
    printData(input);

    int pad_top = 1;
    int pad_bottom = 1;
    int pad_left = 1;
    int pad_right = 1;
    double pad_value = 0.0;
    
    Array output;
    pad_array(input, pad_top, pad_bottom, pad_left, pad_right, pad_value, &output);

    printf("Output Array after padding:\n");
    printData(output);

    return 0;
}
