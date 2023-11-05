#include <stdio.h>
#include <stdlib.h>

void print_tab(int *t, int n)
{
    if (n == 0)
        return;

    printf("[");
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d, ", t[i]);
    }
    printf("%d", t[n - 1]);
    printf("]\n");
}

int schodki(int n, int t[])
{
    if (n == 0)
        return 0;

    int *sub = (int *)calloc((size_t)n + 1, sizeof(int));

    int subCount = 0;
    for (int i = 0; i < n; i++)
    {
        int currentEl = t[i];
        if (currentEl == 0)
        {
            subCount++;
            ++sub[0];
            continue;
        }

        int previousEl = t[i] - 1;
        if (sub[previousEl] > 0)
        {
            --sub[previousEl];
        }
        else
            subCount++;
        ++sub[currentEl];
    }

    return subCount;
}

int main()
{
    int n;
    scanf("%d", &n);
    int *t = (int *)malloc((size_t)n * sizeof(n));
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);

    int stairsCount = schodki(n, t);
    printf("%d\n", stairsCount);
}