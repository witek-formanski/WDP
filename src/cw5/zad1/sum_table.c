#include <stdlib.h>

int *sum_table(int n, int a[]) {
    int *b = (int *)malloc((size_t)n * sizeof(int));

    for (int i = 0; i < n; i++) {
        b[i] = 0;
        for (int j = a[i]; j < n; j++) {
            b[i] += a[j];
        }
    }

    return b;
}