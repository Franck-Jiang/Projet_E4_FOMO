#include <stdio.h>
#include "array.h"

// Fonction ReLU6
double relu6(double x) {
    return (x > 6.0) ? 6.0 : (x > 0.0) ? x : 0.0;
}

// Fonction pour appliquer ReLU6 à tous les éléments d'un tensor
void apply_relu6_to_tensor(double* input, int* input_shape, int input_dim) {
    int size = 1;

    for (int i = 0; i < input_dim; i++){
        size *= input_shape[i];
    }

    for (int i = 0; i < size; i++) {
        input[i] = relu6(input[i]);
    }
}

int main() {
    // Exemple d'utilisation
    double input[] = {-3.0, -1.0, 0.0, 2.5, 5.0, 7.0};
    int input_shape[2] = {2, 3};
    int input_dim = 2;

    printf("Tensor avant ReLU6 :\n");
    printArray(input, input_shape, input_dim);

    // Appliquer ReLU6 au tensor
    apply_relu6_to_tensor(input, input_shape, input_dim);

    // Afficher le tensor après l'application de ReLU6
    printf("Tensor après ReLU6 :\n");
    printArray(input, input_shape, input_dim);

    return 0;
}
