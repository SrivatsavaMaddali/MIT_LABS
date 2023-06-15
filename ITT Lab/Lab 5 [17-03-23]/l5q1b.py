# define a matrix
matrix = [[1, 2], [3, 4], [5, 6]]

# create a new matrix to store the transpose
transpose = [[0, 0, 0], [0, 0, 0]]
# find the transpose using nested loops
for i in range(len(matrix)):
    for j in range(len(matrix[0])):
        transpose[j][i] = matrix[i][j]

# print the original and the transpose matrices
print("Original matrix:")
for row in matrix:
    print(row)

print("Transpose matrix:")
for row in transpose:
    print(row)
