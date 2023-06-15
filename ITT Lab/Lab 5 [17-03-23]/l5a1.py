m = int(input("Enter the lower limit (m): "))
n = int(input("Enter the upper limit (n): "))

def is_prime(num):
    if num <= 1:
        return False
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            return False
    return True

print("Prime numbers between", m, "and", n, "are:")
for num in range(m, n+1):
    if is_prime(num):
        print(num)
