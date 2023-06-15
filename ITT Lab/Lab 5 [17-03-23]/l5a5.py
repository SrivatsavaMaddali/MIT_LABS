my_list = [1, 2, 3, 4, 5]
print("Original:")
print(my_list)
length = len(my_list)
for i in range(length // 2):
    my_list[i], my_list[length - 1 - i] = my_list[length - 1 - i], my_list[i]
print("Reverse:")
print(my_list)
