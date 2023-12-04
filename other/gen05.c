#include <stdio.h>
#include <stdlib.h>

int less_int(const void *a, const void *b)
{
    int _a = *(int *)a;
    int _b = *(int *)b;
    if (_a < _b)
        return -1;
    else if (_a == _b)
        return 0;
    else
        return 1;
}

int main()
{
    int maxN = 1e3;    // maksymalna wartość jaką może przyjąć n
    int maxDist = 1e7; // maksymalna wartość dystansu hotelu od startu

    unsigned int seed;
    scanf("%u", &seed);
    srand(seed);

    int n = (rand() % maxN) + 1;
    printf("%d\n", n);

    int *t = (int *)malloc((unsigned)n * sizeof(int));
    for (int i = 0; i < n; ++i)
        t[i] = rand() % maxDist;
    qsort(t, (unsigned)n, sizeof(int), less_int);

    for (int i = 0; i < n; i++)
        printf("%d %d\n", (rand() % n) + 1, t[i]);
    return 0;
}
