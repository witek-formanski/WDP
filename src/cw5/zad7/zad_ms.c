#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int p(int n, int t[])
{
    int max_sum = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (sum + t[i] < 0)
        {
            sum = 0;
        }
        else
        {
            sum += t[i];
        }

        if (sum > max_sum)
        {
            max_sum = sum;
        }
    }
    return max(sum, max_sum);
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

    int bentley = p(n, t);
    printf("%d\n", bentley);
    free(t);
}