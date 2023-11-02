#include <stdio.h>

int fib(int n) {
    // if (n < 0) return fib(n + 2) - fib(n + 1);
    if (n == 0 || n == 1) return n;

    return fib(n - 1) + fib(n - 2);
}

int fib_sum(int n) {
    int sum = 0;
    for (int i = 0; i < n + 1; i++)
        sum += fib(i);

    return sum;
}

int main() {
    // fib(n+2) - 1 = fib(n) + fib(n-1) + ... + fib(0)
    for (int i = 1; i < 20; i++)
        printf("%d\t%d\n", fib(i), fib_sum(i - 2) + 1);

    return 0;
}