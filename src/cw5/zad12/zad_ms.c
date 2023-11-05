#include <stdio.h>
#include <stdlib.h>

unsigned int *calc_prefix_sums(unsigned int n, unsigned int t[])
{
    unsigned int *sums = (unsigned int *)malloc((size_t)n * sizeof(unsigned int));
    sums[0] = t[0];
    for (unsigned int i = 1; i < n; i++)
    {
        sums[i] = sums[i - 1] + t[i];
    }
    return sums;
}

unsigned int sum_interval(unsigned int start, unsigned int end, unsigned int t[])
{
    if (start == 0)
        return t[end];
    else
        return t[end] - t[start - 1];
}

int find(unsigned int a[], unsigned int size, unsigned int s)
{
    unsigned int *prefixSums = calc_prefix_sums(size, a);
    unsigned int i = 0, j = 0;
    while (i < size && j < size && i<=j)
    {
        unsigned int sum = sum_interval(i, j, prefixSums);
        if (sum < s)
        {
            j++;
        }
        else
        {
            if (sum > s)
                i++;
            else
                // found
                return (int)i;
        }
    }
    return -1;
}

int main()
{
    unsigned int s; scanf("%u", &s);
    unsigned int n; scanf("%u", &n);
    unsigned int* t = (unsigned int*)malloc((size_t)n*sizeof(unsigned int));
    for(unsigned int i = 0; i<n; i++) scanf("%u", &t[i]);

    printf("%d\n", find(t,n,s));
}