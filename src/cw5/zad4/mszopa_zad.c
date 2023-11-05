#include <stdio.h>
#include <stdlib.h>

int abs(int a)
{
    if (a < 0)
        return -a;
    return a;
}

int fit(int c, int n, int v[])
{
    int l = 0, r = n - 1;
    int min = abs(c + v[l] + v[r]);
    while (l + 1 < r)
    {
        int sum = c + v[l] + v[r];
        if (abs(sum) < min)
        {
            min = abs(sum);
            if (min == 0)
                return min;
        }
        if (sum > 0)
        {
            r--;
        }
        else
            l++;
    }
    return min;
}

int main()
{
    int c;
    scanf("%d", &c);
    int n;
    scanf("%d", &n);
    int *v = (int *)malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    int f = fit(c, n, v);
    printf("%d\n", f);
}