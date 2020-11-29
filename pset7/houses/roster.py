from sys import argv, exit
from cs50 import SQL

if len(argv) != 2:
    print("error cli arguments")
    exit()

db = SQL("sqlite:///students.db")

rows = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last, first", argv[1])

for row in rows:
    if row['middle'] != None:
        print(f"{row['first'] + ' ' + row['middle'] + ' ' + row['last']}, born {row['birth']}")
    else:
        print(f"{row['first'] + ' ' + row['last']}, born {row['birth']}")
