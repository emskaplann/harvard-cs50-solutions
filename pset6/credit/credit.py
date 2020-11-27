from cs50 import get_int
from sys import exit

credit = get_int("Number: ")
length = len(str(credit))
digits = [None] * length

if length in [13, 15, 16]:
    i = length - 1
    while i >= 0:
        digits[i] = int(str(credit % 10)[:1])
        credit = credit / 10
        i -= 1

    total = 0
    i = length - 2
    while i >= 0:
        product = digits[i] * 2
        length_of_product = len(str(product))
        if length_of_product > 1:
            j = length_of_product - 1
            while j >= 0:
                total += int(str(product % 10)[:1])
                product = product / 10
                j -= 1
        else:
            total += product
        i -= 2

    i = length - 1
    while i >= 0:
        total += digits[i]
        i -= 2
    # print(total)

    if total % 10 != 0:
        print("INVALID")
        exit()

    if length == 15 and digits[0] == 3 and (digits[1] == 4 or digits[1] == 7):
        print("AMEX")
        exit()
    elif (length == 13 or length == 16) and digits[0] == 4:
        print("VISA")
        exit()
    elif length == 16 and digits[0] == 5 and (digits[1] == 1 or digits[1] == 2 or digits[1] == 3 or digits[1] == 4 or digits[1] == 5):
        print("MASTERCARD")
        exit()
    else:
        print("INVALID")
        exit()
else:
    print("INVALID")
    exit()
