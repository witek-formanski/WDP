#!/bin/bash

test_folder=$1

declare -A tests_dict

shopt -s globstar
for file in tests/*/*/$test_folder/*.in; do
    file_path=$(dirname "${file#tests/}")
    src_file_path=$(dirname "$file_path")
    file_name=$(basename "$file")
    base_name="${file_name%.*}"
    file_number=$(echo $base_name | grep -o '[0-9]\+$')
    name=$(echo $base_name | sed "s/$file_number//")
    full_name="$src_file_path/$name"
    if [ ${tests_dict[$full_name]+_} ]; then
        if (( $file_number > ${tests_dict[$full_name]} )); then
            tests_dict[$full_name]=$file_number
        fi
    else
        tests_dict[$full_name]=$file_number
    fi
done
shopt -u globstar

output_env_var=""
for test_name in "${!tests_dict[@]}"; do
    output_env_var+="$test_name:${tests_dict[$test_name]},"
done

output_env_var=${output_env_var%?}

echo $output_env_var
