import numpy as np

# define two matrices as NumPy arrays
matrix1 = np.array([[1, 2], [3, 4], [5, 6]])
matrix2 = np.array([[7, 8], [9, 10]])

# multiply the matrices using the dot() function
product = np.dot(matrix1, matrix2)

# print the original matrices and the product matrix
print("Matrix 1:")
print(matrix1)

print("Matrix 2:")
print(matrix2)

print("Product matrix:")
print(product)
