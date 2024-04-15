import numpy as np
import tensorflow as tf



def txt(name, input_data : np.ndarray, input_shape : list):
    flat = ",".join(list(input_data.flatten().astype(str)))  
    flat_shape = ",".join(list(np.array(input_shape).flatten().astype(str)))  
    res = ";".join([str(name), flat, flat_shape, str(len(input_shape))])
    return res
                
def create_txt(file: str):
    tensor_details = interpreter.get_tensor_details()
    with open(file, "w") as f:
        for tensor_i in range( len(tensor_details) ):
            tensor = tensor_details[tensor_i]['quantization_parameters']["scales"]
            text = txt(tensor_details[tensor_i]['name'].replace(";", "-"), 
                       tensor, 
                       tensor.shape) + "\n"
            f.write(text)

if __name__ == "__main__":
    interpreter = tf.lite.Interpreter(model_path="Model Interpreter/ei-beer-vs.-cans-fomo-object-detection-tensorflow-lite-int8-quantized-model.lite")
    interpreter.allocate_tensors()

    create_txt("../c/fomo_parameters.txt")