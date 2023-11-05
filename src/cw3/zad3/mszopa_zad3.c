#include <stdio.h>
#include <stdlib.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int countDistinctInArray(int t[], int size)
{
    int distinctCount = 0;
    for (int i = 0; i < size; i++)
    {
        distinctCount++;
        // skip all equal to t[i]     
        int j = i+1;
        while(j < size && t[j] == t[i]) j++;
        i = j-1;

    }
    return distinctCount;
}

int countDistinctElemsInTwoArrays(int a[], int sizeA, int b[], int sizeB)
{
    int c = 0;
    while (sizeA > 0 || sizeB > 0)
    {
        if (sizeA <= 0)
        {
            return c + countDistinctInArray(b, sizeB);
        }
        if (sizeB <= 0)
        {
            return c + countDistinctInArray(a, sizeA);
        }

        int currentElem = min(a[0], b[0]);
        c++;
        // skip current elem
        while (sizeA > 0 && a[0] == currentElem)
        {
            ++a;
            --sizeA;
        }
        while (sizeB > 0 && b[0] == currentElem)
        {
            ++b;
            --sizeB;
        }
    }

    return c;
}

int *scanForArrayOfInt(int *tabSize)
{
    scanf("%d", tabSize);

    int *tab = (int *)malloc((unsigned)(*tabSize) * sizeof(int));
    for (int i = 0; i < *tabSize; i++)
    {
        scanf("%d", &tab[i]);
    }

    return tab;
}

int main()
{
    int sizeA;
    int *a = scanForArrayOfInt(&sizeA);

    int sizeB;
    int *b = scanForArrayOfInt(&sizeB);

    int distincCount = countDistinctElemsInTwoArrays(a, sizeA, b, sizeB);
    printf("%d\n", distincCount);
}