#include <stdlib.h>
#include <stdio.h>

int *sum_table_brute(int n, int a[]) {
    int *b = (int *)malloc((size_t)n * sizeof(int));

    for (int i = 0; i < n; i++) {
        b[i] = 0;
        for (int j = a[i]; j < n; j++) {
            b[i] += a[j];
        }
    }

    return b;
}

int main() {
    int n;
    if (!scanf("%d", &n)) printf("invalid value\n");

    int *a = (int *)malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; i++)
        if (!scanf("%d", &a[i])) printf("invalid value\n");

    int *b = sum_table_brute(n, a);
    for (int i = 0; i < n; i++) printf("%d\n", b[i]);

    free(a);
    free(b);

    return 0;
}