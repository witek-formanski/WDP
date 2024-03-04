import os
import sys

full_file_name = sys.argv[1]
file_name = full_file_name.split('.')[0]
file_extension = full_file_name.split('.')[1]

if (file_extension == 'cpp'):
    os.system(f'g++ @configs/optionsCpp -o src/{file_name}.exe src/{file_name}.cpp')
elif (file_extension == 'c'):
    os.system(f'gcc @configs/options src/{file_name}.c -o src/{file_name}.e')
else:
    print('wrong file extension: ', file_extension)
    sys.exit(1)