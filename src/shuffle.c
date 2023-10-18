#include <stdio.h>
#include <stdlib.h>

// shuffle(7, {3, 2, 8, 1, 9, 3, 6}, 3, {5, 7, 0}) == {3, 5, 2, 7, 8, 0, 1, 9, 3, 6}
// shuffle(3, {5, 7, 0}, 7, {3, 2, 8, 1, 9, 3, 6}) == {5, 3, 7, 2, 0, 8, 1, 9, 3, 6}

int *shuffle(int n, int a[], int m, int b[])
{
    int shuffled_array_size = n + m;
    int *shuffled_array = (int *)malloc((size_t)shuffled_array_size * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        if (i <= m)
            shuffled_array[2 * i] = a[i];
        else
            shuffled_array[m + i] = a[i];
    }

    for (int i = 0; i < m; i++)
    {
        if (i <= n)
            shuffled_array[2 * i + 1] = a[i];
        else
            shuffled_array[n + i] = a[i];
    }

    return shuffled_array;
}

void print_array(int n, int a[])
{
    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

int *get_array(int *n)
{
    scanf("%d", n);
    int *a = (int *)malloc((size_t)*n * sizeof(int));
    for (int i = 0; i < *n; ++i)
        scanf("%d", &a[i]);
    return a;
}

int main()
{

    return 0;
}