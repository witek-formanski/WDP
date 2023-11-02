// https://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/

/*
Let a[i] be the number of binary strings of length i which do not contain any two consecutive 1’s
and which end in 0. Similarly, let b[i] be the number of such strings which end in 1.
We can append either 0 or 1 to a string ending in 0, but we can only append 0 to a string ending in 1

a[]?        b[]?        a[]         b[]

0?          1                       1

00?         01?         10
10

000?        001?        100         101
100         101
010?

0000?       0001?       1000        1001
1000        1001        1010
0100?       0101?
0010?
1010

00000?      00001?      10000       10001
10000       10001       10100       10101
01000?      01001?      10010
00100?      00101?
10100       10101
00010?
10010
01010?

*/

#include <stdio.h>
#include <stdlib.h>

int count_strings(int n) {  // n > 0
    int* a = (int*)malloc((size_t)n * sizeof(int));
    int* b = (int*)malloc((size_t)n * sizeof(int));
    a[0] = b[0] = 1;
    for (int i = 1; i < n; i++) {
        a[i] = a[i - 1] + b[i - 1];
        b[i] = a[i - 1];
    }
    return (a[n - 1] + b[n - 1]) % 1000000007;
}

int main() {
    for (int i = 1; i < 20; i++)
        printf("%d\n", count_strings(i));
    return 0;
}