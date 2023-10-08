import os
import re

files = [f.split(".")[0] for f in os.listdir("tests")]
tests_dict = dict()

for file in files:
    file_number = re.findall(r"\d+", file)[-1]
    file_name = file[:len(file) - len(file_number)]
    if file_name in tests_dict.keys():
        tests_dict[file_name] = max(tests_dict[file_name], int(file_number))
    else:
        tests_dict[file_name] = int(file_number)

output_env_var = ''
for test_name, tests_number in tests_dict.items():
    output_env_var += test_name + ' ' + str(tests_number) + ','
output_env_var = output_env_var.rstrip(output_env_var[-1])

print(output_env_var)