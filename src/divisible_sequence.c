#include <stdio.h>
#include <stdlib.h>

int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

int get_current_divisible_fragment_length(int* t, int i)
{
    int current_divisible_fragment = 1;

    for (int j = i-1; j >= 0; j--)
    {
        if (!t[j] || t[i] % t[j])
        {
            return current_divisible_fragment;
        }

        ++current_divisible_fragment;
    }

    return current_divisible_fragment;
}

int get_max_divisible_fragment(int* t, int n)
{
    int max_divisible_fragment = 0;

    int i = n-1;
    while (i >= 1)
    {
        int current_divisible_fragment = get_current_divisible_fragment_length(t, i);
        max_divisible_fragment = maximum(current_divisible_fragment, max_divisible_fragment);
        i -= current_divisible_fragment;
    }

    return max_divisible_fragment;
}

int main() 
{
    int n;

    if (!scanf("%d", &n)) printf("invalid n provided\n");

    if (n <= 0) 
    {
        printf("n must be positive\n");
        return 1;
    }

    int* t;
    t = (int *)malloc((size_t)n * sizeof(int));

    for (int i = 0; i < n; i++) 
    {
        if (!scanf("%d", &t[i])) printf("invalid t[i] provided\n");
    }

    printf("%d", get_max_divisible_fragment(t, n));
    
    free(t);

    return 0;
}