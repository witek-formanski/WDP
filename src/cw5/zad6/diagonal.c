#include <math.h>
#include <stdlib.h>
#include <stdio.h>

float find_shortest_diagonal(int n, float *a, float *b) {
    int l = 0, r = n -1, m;

    while (l < r) {
        m = (l + r) / 2;
        if (b[m] - a[m] > 0)
            l = m + 1;
        else
            r = m;
    }

    if (l -1 >= 0 && b[l - 1] - a[l - 1] <= b[l] - a[l])
        return sqrt(a[l-1] * a[l-1] + b[l-1] * b[l-1]);
    
    return sqrt(a[l] * a[l] + b[l] * b[l]);
}

int main() {
    int n;
    if (!scanf("%d", &n), printf("invalid value\n"));

    int *a = (int *)malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; i++)
        if (!scanf("%lf", &a[i]), printf("invalid value\n"));

    int *b = (int *)malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; i++)
        if (!scanf("%lf", &b[i]), printf("invalid value\n"));

    printf("%lf", find_shortest_diagonal(n, a, b));

    return 0;
}