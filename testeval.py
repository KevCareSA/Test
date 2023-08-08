iput = "[1, 2, 3, 4]"
try:
    value = eval(iput)
    if type(value) not in [int, float]:
        value = iput
except (NameError, SyntaxError, TypeError, ValueError):
    value = iput

print(type(value), value)
