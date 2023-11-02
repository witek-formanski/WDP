#include <stdbool.h>
#include <stdio.h>

bool is_prime(int n) {
    if (n <= 1) return false;

    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0) return false;

    return true;
}

int main() {
    int n;
    if (!scanf("%d", &n)) printf("invalid value");

    printf("%d", is_prime(n));

    return 0;
}