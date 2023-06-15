string="Hi!!!! How are you? You know, I was waiting for you."
newstring=""
for i in string:
    if i.isalpha() or i.isspace():
        newstring=newstring+i

print(newstring)
