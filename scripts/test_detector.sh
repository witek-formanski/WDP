#!/bin/bash

test_folder=$1

declare -A tests_dict

for file in tests/$test_folder/*; do
    file_name=$(basename "$file")
    base_name="${file_name%.*}"
    file_number=$(echo $base_name | grep -o '[0-9]\+$')
    name=$(echo $base_name | sed "s/$file_number//")
    if [ ${tests_dict[$name]+_} ]; then
        if (( $file_number > ${tests_dict[$name]} )); then
            tests_dict[$name]=$file_number
        fi
    else
        tests_dict[$name]=$file_number
    fi
done

output_env_var=""
for test_name in "${!tests_dict[@]}"; do
    output_env_var+="$test_name:${tests_dict[$test_name]},"
done

output_env_var=${output_env_var%?}

echo $output_env_var
