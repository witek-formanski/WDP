#include <stdbool.h>
#include <stdio.h>

bool is_sparse(int n) {
    while (n) {
        if ((n & 3) == 3) return false;

        n >>= 1;
    }

    return true;
}

int count_sparse_numbers_brute(int n) {
    int counter = 0;

    while (n > 0) {
        if (is_sparse(n)) counter++;
        n--;
    }

    return counter;
}

int main() {
    int n;
    if (!scanf("%d", &n)) printf("invalid value");

    printf("%d", count_sparse_numbers_brute(n));

    /* surprise - Fibonacci! */
    // for (int i = 0; i < 13; i++) {
    //     printf("count_sparse(%d) \t- count_sparse(%d) \t= %d\n",
    //            1 << (i + 1),
    //            1 << (i),
    //            count_sparse_numbers_brute(1 << (i + 1)) - count_sparse_numbers_brute(1 << (i)));
    // }

    return 0;
}