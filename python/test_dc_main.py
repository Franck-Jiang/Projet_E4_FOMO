import tensorflow as tf
import numpy as np

# Initialiser les données d'entrée et le noyau avec les mêmes valeurs que celles utilisées dans l'exemple C
input_data = np.arange(1, 676).reshape((1, 15, 15, 3))  # Redimensionner l'entrée pour être de taille (1, 16, 16, 3)
kernel = np.arange(0.5, 27.5).reshape((1, 3, 3, 3))  # Redimensionner le noyau pour être de taille (3, 3, 3, 3)


# Convertir les tableaux NumPy en tenseurs TensorFlow
input_data_tf = tf.constant(input_data, dtype=tf.float32)
kernel_tf = tf.constant(kernel, dtype=tf.float32)




# Fonction de convolution profonde (depthwise convolution)
output = tf.nn.depthwise_conv2d(input_data_tf, kernel_tf,padding='VALID' ,strides=[1,1,1,1])

# Afficher les données de sortie
print(output)

