/*
złożoność czasowa:
    T(n) = O(n)

złożoność pamięciowa:
    M(n) = O(n)
*/

#include <limits.h>

int sparse_shuffle_bits(int n) {
    int x = 0;
    int temp;
    int bits = 0;

    while (n) {
        temp = n & 1;
        temp <<= bits;
        x += temp;
        n /= 4;
        bits += 2;
    }
    
    return x;
}

#include <stdio.h>

int main() {
    printf("%d", sparse_shuffle_bits(-44));
}