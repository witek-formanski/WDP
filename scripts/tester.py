import os
import sys
exit_code = 0

full_file_name = sys.argv[1]
file_name = full_file_name.split(".")[0]
file_extension = full_file_name.split(".")[1]
highest_test_number = int(sys.argv[2])
if len(sys.argv) == 4:
    test_folder_name = sys.argv[3]
else:
    test_folder_name = "tests"

for test_number in range(highest_test_number+1):
    print(test_number)

    tests_out_path = "{}}/{}/{}{}.out".format(test_folder_name, file_extension, file_name, test_number)
    with open(tests_out_path, "r") as out:
        expected_output = out.read().strip()
        
    tests_in_path = "{}/{}/{}{}.in".format(test_folder_name, file_extension, file_name, test_number)
    if (file_extension == "cpp"):
        os.system(os.getcwd() + "/src/{}.exe <{} >{}".format(file_name, tests_in_path, "my_output.out"))
    elif (file_extension == "c"):
        os.system(os.getcwd() + "/src/{}.e <{} >{}".format(file_name, tests_in_path, "my_output.out"))
    else:
        print("wrong file extension:", file_extension)
        sys.exit(1)
    with open("my_output.out", "r") as out:
        my_output = out.read().strip()
    
    if((my_output != expected_output)):
        exit_code = 1
        print("ERROR")
        print("my output:")
        print(my_output)
        print("expected output:")
        print(expected_output)
        print("_________________________\n")
    else:
        print("OK\n")
        
os.remove("my_output.out")
sys.exit(exit_code)