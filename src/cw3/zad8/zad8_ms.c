#include <stdio.h>
#include <stdlib.h>

int decompress_number(int *n)
{
    int i = 1;
    while (*n % 2 == 0)
    {
        *n /= 2;
        i++;
    }

    ++*n;
    *n/=2;

    return i;
}

int *dekompresuj(int n, int t[], int *w)
{
    *w = n;
    int *decompressed = (int *)malloc((size_t)n * sizeof(int));
    int ci = 0;
    for (int i = 0; i < n; i++)
    {
        int itCount = decompress_number(&t[i]);
        if (itCount + i >= n)
        {
            // calculate new min size for array
            *w += itCount + ci - n;
            // resize array
            t = realloc(t, (size_t)*w * sizeof(int));
        }
        for (int j = 0; j < itCount; j++)
        {
            decompressed[ci++] = t[i];
        }
    }
    return decompressed;
}

int main()
{
    int n;
    if(!scanf("%d", &n)) printf("wrong input");
    int *t = (int *)malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        if(!scanf("%d", &t[i])) printf("wrong input");
    }

    int w;
    int *dec = dekompresuj(n, t, &w);
    for(int i = 0; i<w; i++){
        printf("%d\n", dec[i]);
    }
}