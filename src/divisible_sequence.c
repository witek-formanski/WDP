#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    if (n <= 0) 
    {
        printf("n must be positive\n");
        return 1;
    }

    int* t;
    t = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &t[i]);
    }

    int max_divisible_fragment = 0;
    int current_divisible_fragment = 1;

    for (int i = 0; i < n - 1; i++) 
    {
        if (t[i + 1] % t[i] == 0) 
        {
            current_divisible_fragment++;
        } 
        else 
        {
            if (current_divisible_fragment > max_divisible_fragment) 
            {
                max_divisible_fragment = current_divisible_fragment;
            }
            current_divisible_fragment = 1;
        }
    }


    if (current_divisible_fragment > max_divisible_fragment) 
    {
        max_divisible_fragment = current_divisible_fragment;
    }

    printf("Najdluzszy dzielny fragment: %d\n", max_divisible_fragment);

    return 0;
}
