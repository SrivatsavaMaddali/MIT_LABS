def list_sum(lst):
    if len(lst) == 0:
        return 0
    elif len(lst) == 1:
        return lst[0]
    else:
        return lst[0] + list_sum(lst[1:])

my_list = [1, 2, 3, 4, 5]
print(my_list)
print("Sum:",list_sum(my_list))
