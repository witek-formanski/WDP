import os
import sys

full_file_name = sys.argv[1]
file_name = full_file_name.split(".")[0]
file_extension = full_file_name.split(".")[1]

if (file_extension == "cpp"):
    os.system("g++ -o src/{}.exe src/{}.cpp".format(file_name, file_name))
elif (file_extension == "c"):
    os.system("gcc @configs/options src/{}.c -o src/{}.e".format(file_name, file_name))
else:
    print("wrong file extension: ", file_extension)
    sys.exit(1)