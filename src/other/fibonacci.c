#include <stdio.h>

// the stupid way
// T(n) = O(2^n)
int fib_recursive(int n) {
    // if (n < 0) return fib(n + 2) - fib(n + 1);
    if (n == 0 || n == 1) 
        return n;

    return fib(n - 1) + fib(n - 2);
}

// the basic way
// T(n) = O(n)
int fib_iterative(int n) {
    if (n == 0 || n == 1) 
        return n;
    
    int prev = 0, curr = 1, temp;
    for (int i = 2; i <= n; i++) {
        temp = prev + curr;
        prev = curr;
        curr = temp;
    }

    return curr;
}

void multiply(int F[2][2], int M[2][2]);
void power(int F[2][2], int n);
int M[2][2] = {{1, 1}, {1, 0}};

// the smart way
// T(n) = O(log n)
int fib(int n) {
    if (n == 0)
        return 0;
    int F[2][2] = {{1, 1}, {1, 0}};
    power(F, n - 1);
    return F[0][0];
}

void power(int F[2][2], int n) {
    if (n == 0 || n == 1)
        return;
    
    power(F, n / 2);
    multiply(F, F);

    if (n % 2 != 0)
        multiply(F, M);
}

void multiply(int F[2][2], int M[2][2]) {
    int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

// returns sum of the n first Fibonacci numbers
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