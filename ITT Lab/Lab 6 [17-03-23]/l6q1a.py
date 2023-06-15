string="racecar"
string = string.lower().replace(" ", "")
if string==string[::-1]:
    print("Paindrome")
else:
    print("Not Palindrome")

