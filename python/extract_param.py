import json
import numpy as np

def txt(name, input_data : np.ndarray, input_shape : list, file: str):
    flat = ",".join(list(input_data.flatten().astype(str)))  
    flat_shape = ",".join(list(np.array(input_shape).flatten().astype(str)))  
    res = ";".join([str(name), flat, flat_shape, str(len(input_shape))])
    print(res)
    return res
        

def create_txt(file: str):
    """"
    PLACEHOLDER
    """
    shapes = [(1, 10), (2, 5), (5, 2), (10, 1)]
    with open(file, "w") as f:
        for i in range (5):
            text = txt(i, np.array([ [0 ,1.111*i , 2*i , i , -2*i],[3.14 , -1/(i+1) ,1/(i+1) ,2*i**2 ,2*(10-i)]]), shapes[i%4], file) + "\n"
            f.write(text)
            
            
if __name__ == "__main__":
    test_input = np.array([ [1.258 ,2.159 ,3.222 ,4.144 ,5.999],
                        [3.14 ,444 ,853.1 ,3.9 ,5.5]])

    create_txt("../c/test.txt")