/*
42dec = 101010bin

nearest power of two (less than n):
32dec = 100000bin

8:
100000
100001
100010
100100
100101
101000
101001
101010

5:
10000
10001
10010
10100
10101

3:
1000
1001
1010

2:
100
101

1:
10

1:
1

Fibonacci!

number of sparse numbers is equal to the sum
of Fibonacci sequence elements

fib(n+2) - 1 = fib(n) + fib(n-1) ... + fib(0)

*/

#include <stdbool.h>
#include <stdio.h>

bool is_sparse(int n) {
    while (n) {
        if ((n & 3) == 3) return false;

        n >>= 1;
    }

    return true;
}

int nearest_lower_pow_of_two(int n) {
    if (n < 1) return -1000;

    int pow = 0;

    while (n != 1) {
        n >>= 1;
        pow += 1;
    }

    return pow;
}

int fib(int n) {
    if (n < 0) return -1000;
    if (n == 0) return 0;

    int prev1;
    int prev2 = 0;
    int fib = 1;
    for (int i = 0; i < n - 1; i++) {
        prev1 = prev2;
        prev2 = fib;
        fib = prev1 + prev2;
    }

    return fib;
}

int count_sparse_numbers(int n) {
    if (n == 0) return 0;

    int pow = nearest_lower_pow_of_two(n);
    int count = fib(pow + 2);

    int two = 1 << pow;
    while (two < n) {
        two++;
        if (is_sparse(two))
            count++;
    }

    return count;
}

int main() {
    int n;
    if (!scanf("%d", &n)) printf("invalid value");

    printf("%d", count_sparse_numbers(n));

    return 0;
}