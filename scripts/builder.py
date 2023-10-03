import os
import sys

file_name = sys.argv[1]

os.system("g++ -o ../src/{}.exe {}.cpp".format(file_name, file_name))