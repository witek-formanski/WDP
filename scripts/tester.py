import os
import sys
exit_code = 0

file_name = sys.argv[1]
highest_test_number = int(sys.argv[2])

for test_number in range(highest_test_number+1):
    print(test_number)

    tests_out_path = "../tests/{}{}.out".format(file_name, test_number)
    with open(tests_out_path, "r") as out:
        expected_output = out.read().strip()
        
    tests_in_path = "../tests/{}{}.in".format(file_name, test_number)
    os.system(os.getcwd() + "../src/{}.exe <{} >{}".format(file_name, tests_in_path, "my_output.out"))
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