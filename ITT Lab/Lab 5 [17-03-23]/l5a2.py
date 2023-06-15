def bubble_sort(lst):
    n = len(lst)
    # Traverse through all array elements
    for i in range(n):
        # Last i elements are already sorted
        for j in range(0, n-i-1):
            # Swap if the element found is greater than the next element
            if lst[j] > lst[j+1]:
                lst[j], lst[j+1] = lst[j+1], lst[j]

my_list = [3, 8, 1, 9, 4, 6, 2, 7, 5]
print("Original list:")
print(my_list)
bubble_sort(my_list)
print("Sorted list:")
print(my_list)
