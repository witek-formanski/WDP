#include <stdio.h>
#include <stdlib.h>

// -1 if a+b<c, 0 on equality, 1 otherwise
int triangle_inequality(int a, int b, int c)
{
    int s = a + b;
    if (s < c)
        return -1;
    if (s == c)
        return 0;
    return 1;
}

int trojki(int size, int tab[])
{
    int c = 0;
    for (int ai = 0; ai < size; ai++)
    {
        for (int bi = ai + 1; bi < size; bi++)
        {
            for (int ci = bi + 1; ci < size; ci++)
            {
                int status = triangle_inequality(tab[ai], tab[bi], tab[ci]);
                if (status <= 0)
                {
                    if (status == 0)
                        ci++;
                    c += size - ci;
                    break;
                }
            }
        }
    }
    return c;
}

int main()
{
    int n;
    scanf("%d", &n);
    int *t = (int *)malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t[i]);
    }

    printf("%d\n", trojki(n, t));
}