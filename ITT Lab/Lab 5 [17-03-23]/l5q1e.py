def sum_natural_numbers(n):
    if n == 1:
        return 1
    else:
        return n + sum_natural_numbers(n-1)

n=int(input("Sum till which number?\n"))
print("Sum is",sum_natural_numbers(n))
