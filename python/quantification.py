import numpy as np

def quantize_to_uint8(value):
    return np.uint8(0.00390625 * (value + 128))

def quantize_array_to_uint8(array):
    return np.clip(( 0.00390625 * (array + 128)), 0, 255).astype(np.uint8)

# Exemple d'utilisation de la fonction
input_value = 100.5
output_value = quantize_to_uint8(input_value)
print("Quantized value:", output_value)

input_array = np.array([100.5, 200.7, 50.2])
output_array = quantize_array_to_uint8(input_array)
print("Quantized array:", output_array)
