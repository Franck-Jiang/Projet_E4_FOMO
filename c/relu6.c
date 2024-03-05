#include <stdio.h>

// Fonction ReLU6
float relu6(float x) {
    return (x > 6.0) ? 6.0 : (x > 0.0) ? x : 0.0;
}

// Fonction pour appliquer ReLU6 à tous les éléments d'un tensor
void apply_relu6_to_tensor(float *tensor, int size) {
    for (int i = 0; i < size; i++) {
        tensor[i] = relu6(tensor[i]);
    }
}

int main() {
    // Exemple d'utilisation
    float myTensor[] = {-3.0, -1.0, 0.0, 2.5, 5.0, 7.0, 10.0};
    int tensorSize = sizeof(myTensor) / sizeof(myTensor[0]);

    // Appliquer ReLU6 au tensor
    apply_relu6_to_tensor(myTensor, tensorSize);

    // Afficher le tensor après l'application de ReLU6
    printf("Tensor après ReLU6 :\n");
    for (int i = 0; i < tensorSize; i++) {
        printf("%f ", myTensor[i]);
    }

    return 0;
}
