import re


iput = input()

print(re.findall(r'"[^"]*"|\'[^\']*\'|\S+', iput))
