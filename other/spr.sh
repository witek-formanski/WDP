#!/usr/bin/bash

opcje="-std=c17 -pedantic -Wall -Wextra -Wformat-security -Wduplicated-cond -Wfloat-equal -Wshadow -Wconversion -Wjump-misses-init -Wlogical-not-parentheses -Wnull-dereference -Wvla -Werror -fstack-protector-strong -fsanitize=undefined -fno-sanitize-recover -g -fno-omit-frame-pointer -O1"

gcc $opcje lab05.c -o wzo #zastąp lab05 nazwą wzorcówki
gcc $opcje brut05.c -o brut #zastąp brut05 nazwą bruta
gcc $opcje gen05.c -o gen #zastąp gen05 nazwą generatorki

test_nr=1000 #ustaw ile testów chcesz wykonać

for(( i=1; i<=$test_nr; i++)) do
    echo $i | ./gen > ./wejscie.in
    ./brut < ./wejscie.in > brut.out
    ./wzo < ./wejscie.in > wzo.out

    if diff -qb brut.out wzo.out;
    then 
        echo "test $i           OK";
    else 
        echo "test $i           ZLE";
        break;
    fi
done
