import re

states = "Mississippi Alabama Texas Massachusetts Kansas"
statesList = []

# search for word ending in "xas" and store in statesList[0]
match = re.search(r'\b\w*xas\b', states)
if match:
    statesList.append(match.group(0))
# search for word beginning with "k" and ending in "s" (case insensitive) and store in statesList[1]
pattern = re.compile(r'\bK\w*s\b', re.I)
match = pattern.search(states)
if match:
    statesList.append(match.group(0))

# search for word beginning with "M" and ending in "s" and store in statesList[2]
match = re.search(r'\bM\w*s\b', states)
if match:
    statesList.append(match.group(0))

# search for word ending in "a" and store in statesList[3]
match = re.search(r'\b\w*a\b', states)
if match:
    statesList.append(match.group(0))

# search for word beginning with "M" and store at the beginning of the string in statesList[4]
match = re.search(r'\bM\w*', states)
if match:
    statesList.append(match.group(0))

# output the array statesList to the screen
print(statesList)
