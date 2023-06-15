my_list = [1, 2, 3, 2, 4, 5, 1, 6, 7, 7, 8, 9]
print(my_list)
new_list = []
for i in my_list:
    if i not in new_list:
        new_list.append(i)
print("After removing duplicates:")
print(new_list)
