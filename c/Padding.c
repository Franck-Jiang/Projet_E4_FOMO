#include <stdio.h>
#include <stdlib.h>

void pad_array(float* input, int height, int width, int pad_top, int pad_bottom, int pad_left, int pad_right, float pad_value, float* output) {
    int padded_height = height + pad_top + pad_bottom;
    int padded_width = width + pad_left + pad_right;

    for (int i = 0; i < padded_height; i++) {
        for (int j = 0; j < padded_width; j++) {
            if (i < pad_top || i >= height + pad_top || j < pad_left || j >= width + pad_left) {
                output[i * padded_width + j] = pad_value;
            } else {
                int original_row = i - pad_top;
                int original_col = j - pad_left;
                output[i * padded_width + j] = input[original_row * width + original_col];
            }
        }
    }
}

int main() {
    int height = 3;
    int width = 3;
    float input[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    float output[16]; 
    int pad_top = 1;
    int pad_bottom = 1;
    int pad_left = 1;
    int pad_right = 1;
    float pad_value = 0;

    pad_array(input, height, width, pad_top, pad_bottom, pad_left, pad_right, pad_value, output);
    printf("Output Array after padding:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%.1f ", output[i * 5 + j]);
        }
        printf("\n");
    }

    return 0;
}
