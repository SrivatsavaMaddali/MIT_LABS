import re

string = "The quick brown fox jumps over the lazy dog"
pattern = "brown"
replacement = "red"

new_string = re.sub(pattern, replacement, string)

print(new_string)
