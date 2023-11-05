#include <stdio.h>
#include <stdlib.h>

int daleko(int n, int a[])
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= i + max && i < j; j--)
        {
            if (a[j] > a[i])
            {
                int odl = j - i;
                if (odl > max)
                    max = odl;
                break;
            }
        }
    }
    return max;
}

int main()
{
    int n;
    if(!scanf("%d", &n)) printf("wrong input");
    int *a = (int *)malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; i++)
        if(!scanf("%d", &a[i])) printf("wrong input");

    printf("%d\n", daleko(n, a));
}