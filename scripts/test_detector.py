import os
import re
import sys

test_folder = sys.argv[1]

tests_dict = {}

for root, dirs, files in os.walk('tests'):
    for file in files:
        if file.endswith('.in') and root.endswith(test_folder):
            src_file_path = os.path.dirname(root)
            file_name = os.path.basename(file)
            base_name = os.path.splitext(file_name)[0]
            file_number = int(re.findall(r'\d+$', base_name)[0])
            name = re.sub(r'\d+$', '', base_name)
            full_name = os.path.join(src_file_path, name)
            if full_name in tests_dict:
                if file_number > tests_dict[full_name]:
                    tests_dict[full_name] = file_number
            else:
                tests_dict[full_name] = file_number

output_env_var = ""
for test_name in tests_dict:
    output_env_var += f"{test_name}:{tests_dict[test_name]},"

output_env_var = output_env_var[:-1]

print(output_env_var)
