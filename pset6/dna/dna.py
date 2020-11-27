import csv
from sys import argv, exit

if len(argv) == 2:
    print("invalid input")
    exit(1)

new_dict = {}

with open(argv[1], newline='') as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
        new_dict[row['name']] = {
            'agatc': int(row['AGATC']),
            'ttttttct': int(row['TTTTTTCT']),
            'aatg': int(row['AATG']),
            'tctag': int(row['TCTAG']),
            'gata': int(row['GATA']),
            'tatc': int(row['TATC']),
            'gaaa': int(row['GAAA']),
            'tctg': int(row['TCTG'])
        }
counter_dict = {"agatc": 0, "ttttttct": 0, "aatg": 0, "tctag": 0, "gata": 0, "tatc": 0, "gaaa": 0, "tctg": 0}
list_of_names = ["agatc", "ttttttct", "aatg", "tctag", "gata", "tatc", "gaaa", "tctg"]
with open(argv[2], 'r') as file:
    text = file.read().replace('\n', '')
    for i in range(len(text)):
        for name in list_of_names:
            length = len(name)
            if text[i:(i+length)] == name.upper():
                j = i
                counter = 0
                while text[j:(j+length)] == name.upper():
                    counter += 1
                    j += length
                if counter > counter_dict[name]:
                    counter_dict[name] = counter

for people in new_dict:
    if new_dict[people] == counter_dict:
        print(people)
        exit(0)

print("No match")
exit(1)