#include <stdio.h>
#include <stdlib.h>

int abs(int a)
{
    if (a >= 0)
        return a;
    return -a;
}

int blisko_zera(int *v, int n)
{
    int i = 0, j = n - 1;
    int isIncreasing = v[0] < v[1];
    while (i + 1 < j)
    {
        int cent = (i + j) / 2;
        if (cent[v] == 0)
        {
            return 0;
        }

        if (isIncreasing)
        {
            if (v[cent] < 0)
            {
                i = cent;
            }
            else
            {
                j = cent - 1;
            }
        }
        else
        {
            if (v[cent] > 0)
            {
                i = cent;
            }
            else
            {
                j = cent - 1;
            }
        }
    }
    
    return abs(v[j]);
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

    int nearestAbsZero = blisko_zera(t, n);
    printf("%d\n", nearestAbsZero);

    free(t);
}