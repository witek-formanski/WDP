#include <stdio.h>
#include <stdlib.h>

int abs(int a)
{
    if (a >= 0)
        return a;
    return - a;
}

int malo(int n, int t[])
{
    int l = 0, p = n - 1;
    while (l + 1 < p)
    {
        int abs_l = abs(t[l]), abs_p = abs(t[p]);
        if (abs_l < abs_p)
        {
            p--;
        }
        else
        {
            if (abs_l > abs_p)
            {
                l++;
            }
            else
            {
                break;
            }
        }
    }
    return abs(t[l] + t[p]);
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

    int little = malo(n,t);
    printf("%d\n", little);

    free(t);
}