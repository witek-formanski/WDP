#include <stdlib.h>
#include <stdio.h>

// k = b.size()
// k >= 3
// set(b) = {0, 1}
// n-th element of sequence determined by b array of zeros and ones
// n >= 0

int bonifacy(int n, int k, int b[])
{
    if (n == 0)
        return 0;

    if (n == 1 || n == 2)
        return 1;

    // if (b[n % k] == 0)
    //     return bonifacy(n-1,k,b) + bonifacy(n-2,k,b);

    // if (b[n % k] == 1)
    //     return bonifacy(n-1,k,b) + bonifacy(n-3,k,b);

    return bonifacy(n - 1, k, b) + bonifacy(n - 2 - b[n % k], k, b);
}

void print_array(int n, int a[])
{
    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

int *get_array(int *n)
{
    if (!scanf("%d", n)) printf("invalid value provided");
    int *a = (int *)malloc((size_t)*n * sizeof(int));
    for (int i = 0; i < *n; ++i)
        if (!scanf("%d", &a[i])) printf("invalid value provided");
    return a;
}

int main()
{
    int n, k;
    if (!scanf("%d", &n)) printf("invalid value provided");
    int *b = get_array(&k);

    printf("%d", bonifacy(n, k, b));

    free(b);

    return 0;
}
