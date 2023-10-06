import os
import re

files = [f.split(".")[0] for f in os.listdir("tests")]
file_names = dict()

for file in files:
    file_number = re.findall(r"\d+", file)[-1]
    file_name = file[:len(file) - len(file_number)]
    if file_name in file_names.keys():
        file_names[file_name] = max(file_names[file_name], int(file_number))
    else:
        file_names[file_name] = int(file_number)
    print(file_number)
    print(file_name)

print(file_names)