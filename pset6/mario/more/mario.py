from cs50 import get_int

h = -1
while h <= 0 or h > 8:
    h = get_int("Height: ")

for i in range(h):
    for j in range(h-(i+1)):
        print(" ", end="")

    for k in range(i+1):
        print("#", end="")

    print("  ", end="")

    for k in range(i+1):
        print("#", end="")
    print()
