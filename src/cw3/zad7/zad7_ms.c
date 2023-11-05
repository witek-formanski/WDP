#include <stdio.h>
#include <stdlib.h>

/// @brief
/// @param n
/// @param t
/// @return array of indexes ending seeked divisions of the set t. -1 means the end of array
int *podziel(int n, int t[])
{
    int max;
    int count = 0;
    int *indexes = (int *)malloc((size_t)n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        if (t[i] > max)
        {
            max = t[i];
        }

        if (max == i)
        {
            // insert
            indexes[count++] = i;
            max = -1;
        }
    }

    indexes[count] = -1;
    return indexes;
}

int main()
{
    int n;
    if(!scanf("%d", &n)) printf("wrong input");

    int *t = (int *)malloc((unsigned)n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        if(!scanf("%d", &t[i])) printf("wrong input");
    }

    int *indexes = podziel(n, t);
    for (int i = 0; i < n; i++)
    {
        if (indexes[i] == -1)
            break;
        printf("%d\n", indexes[i]);
    }
}