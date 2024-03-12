import numpy as np




input_image = np.load("input_image_cd.npy")
output_image = np.load('output_image_cd_strides.npy')


# Vérifier les dimensions
if input_image.shape == output_image.shape:
    print("Les dimensions de l'entrée et de la sortie sont identiques.")
else:
    print("Les dimensions de l'entrée et de la sortie sont différentes.")


print(output_image.shape)