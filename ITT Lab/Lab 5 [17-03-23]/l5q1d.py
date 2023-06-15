import numpy as np

# define two matrices as NumPy arrays
matrix1 = np.array([[1, 2], [3, 4]])
matrix2 = np.array([[7, 8], [9, 10]])

# Adding the matrices using the add() function
Add= np.add(matrix1, matrix2)

# print the original matrices and the result matrix
print("Matrix 1:")
print(matrix1)

print("Matrix 2:")
print(matrix2)

print("Result matrix:")
print(Add)
