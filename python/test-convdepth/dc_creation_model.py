import tensorflow as tf
import numpy as np

input_image = np.load('input_image_cd.npy')


#cas SAME

# Créer un modèle séquentiel avec la couche DepthwiseConv2D
model = tf.keras.Sequential()
model.add(tf.keras.layers.DepthwiseConv2D(kernel_size=(3, 3), 
                                            strides=(1, 1), padding='same',
                                            depth_multiplier=1, use_bias=True,
                                            input_shape=(48, 48, 16)))

# Construction explicite du modèle
model.build(input_shape=(1, 48, 48, 16))


# Appliquer le modèle à l'image d'exemple
output_image = model.predict(input_image)



# Enregistrer l'image de sortie
np.save("output_image_cd_same.npy", output_image)

# Enregistrer les poids du modèle
model.save_weights("model_weights_cd_same.h5")

model.save("model_cd_same")



#cas VALID

# Créer un modèle séquentiel avec la couche DepthwiseConv2D
model = tf.keras.Sequential()
model.add(tf.keras.layers.DepthwiseConv2D(kernel_size=(3, 3), 
                                            strides=(1, 1), padding='valid',
                                            depth_multiplier=1, use_bias=True,
                                            input_shape=(48, 48, 16)))

# Construction explicite du modèle
model.build(input_shape=(1, 48, 48, 16))


# Appliquer le modèle à l'image d'exemple
output_image = model.predict(input_image)



# Enregistrer l'image de sortie
np.save("output_image_cd_valid.npy", output_image)

# Enregistrer les poids du modèle
model.save_weights("model_weights_cd_valid.h5")

model.save("model_cd_valid")



# cas same + strides

# Créer un modèle séquentiel avec la couche DepthwiseConv2D
model = tf.keras.Sequential()
model.add(tf.keras.layers.DepthwiseConv2D(kernel_size=(3, 3), 
                                            strides=(2, 2), padding='valid',
                                            depth_multiplier=1, use_bias=True,
                                            input_shape=(48, 48, 16)))

# Construction explicite du modèle
model.build(input_shape=(1, 48, 48, 16))


# Appliquer le modèle à l'image d'exemple
output_image = model.predict(input_image)



# Enregistrer l'image de sortie
np.save("output_image_cd_strides.npy", output_image)

# Enregistrer les poids du modèle
model.save_weights("model_weights_cd_strides.h5")

model.save("model_cd_strides")












## test à la main

# Afficher la forme de l'image de sortie
#print("Forme de l'image de sortie :", output_image.shape)


# Afficher les poids de chaque couche
#for layer in model.layers:
#    print("Poids de la couche", layer.name)
#    weights = layer.get_weights()
#    for i, weight in enumerate(weights):
#        print("Poids {} :".format(i), weight.shape)