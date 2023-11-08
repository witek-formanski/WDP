/*
złożoność czasowa:
    przy założeniu, że operacje bitowe i arytmetyczne są w O(1):
    T(n) = O(1)

    tak naprawdę:
    T(n) = O(n)

złożoność pamięciowa:
    M(n) = O(n)
*/

#include <limits.h>

int sparse_shuffle_bits(int n) {
    return n & ((INT_MAX / 3) << 1 + 1);
}

#include <stdio.h>

int main() {
    printf("%d", sparse_shuffle_bits(-44));
}