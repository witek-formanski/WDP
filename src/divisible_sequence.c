#include <stdio.h>
#include "common_library.h"

int get_current_divisible_fragment_length(int* tab, int i)
{
    int current_divisible_fragment = 1;
    for (int j = i; j > 1; --j)
    {
        if (!(tab[i] % tab[j-1]))
        {
            return current_divisible_fragment;
        }

        ++current_divisible_fragment;
    }

    return current_divisible_fragment;
}

int get_max_divisible_fragment(int* tab, int n)
{
    int max_divisible_fragment = 0;

    for (int i = n; i > 1; --i) 
    {
        int current_divisible_fragment = get_current_divisible_fragment_length(tab, i);
        max_divisible_fragment = max(current_divisible_fragment, max_divisible_fragment);
    }
    return max_divisible_fragment;
}

int main() {
    int n;

    scanf("%d", &n);

    if (n <= 0) 
    {
        printf("n must be positive\n");
        return 1;
    }

    int* tab;
    tab = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &tab[i]);
    }

    printf("%d", get_max_divisible_fragment(tab, n));

    return 0;
}