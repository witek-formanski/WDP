#include <stdio.h>
#include <stdlib.h>

int bin(int n, int *a)
{
    int l = 0, p = n - 1;

    while (l < p)
    {
        int pivot = (l + p) / 2;

        int diff = a[pivot] - a[pivot - 1];
        if (diff > 0)
        {
            p = pivot;
        }
        else
        {
            if (diff == 0)
            {
                return a[pivot];
            }

            l = pivot + 1;
        }
    }
    return a[p];
}

int main()
{
    int n;
    if(!scanf(("%d", &n))) printf("wrong input");
    int *t = (int *)malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        if(!scanf(("%d", &t[i]))) printf("wrong input");
    }

    printf("%d\n", bin(n, t));
}