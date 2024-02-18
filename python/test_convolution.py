
import numpy as np
import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'
import tensorflow as tf
from keras.layers import Conv2D

'''
Conv2D(filters, 
       kernel_size, 
       strides=(1, 1), 
       padding='valid', 
       data_format=None, 
       dilation_rate=(1, 1), 
       groups=1, 
       activation=None, 
       use_bias=True, 
       kernel_initializer='glorot_uniform', 
       bias_initializer='zeros', 
       kernel_regularizer=None, 
       bias_regularizer=None, 
       activity_regularizer=None, 
       kernel_constraint=None, 
       bias_constraint=None, 
       **kwargs)
'''

filter1 = [[1, 0, 0, 0, 0],
           [1, 0, 0, 0, 0],
           [1, 0, 0, 0, 0],
           [1, 0, 0, 0, 0],
           [1, 0, 0, 0, 0]]

kernel1 = [[0, 1, 0],
           [0, 1, 0],
           [0, 1, 0]]



input_matrix = np.array([[1, 2, 3, 4, 5],
                        [6, 7, 8, 9, 10],
                        [11, 12, 13, 14, 15],
                        [16, 17, 18, 19, 20],
                        [21, 22, 23, 24, 25]])

# Définir le filtre (2x2)
filter_matrix = np.array([[2, 0],
                         [1, 2]])

# Ajouter une dimension pour indiquer le nombre de canaux (1 dans ce cas car c'est une image en niveaux de gris)
input_matrix = input_matrix.reshape((1, 5, 5, 1))
filter_matrix = filter_matrix.reshape((2, 2, 1, 1))

# Convertir les matrices en tenseurs TensorFlow
input_tensor = tf.constant(input_matrix, dtype=tf.float32)
filter_tensor = tf.constant(filter_matrix, dtype=tf.float32)

# Appliquer la convolution
result = tf.nn.conv2d(input_tensor, filter_tensor, strides=[1, 1, 1, 1], padding='VALID')

# Afficher le résultat
print(result.numpy().reshape(4, 4))