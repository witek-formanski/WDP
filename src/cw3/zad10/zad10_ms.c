#include <stdio.h>
#include <stdlib.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int wrzucaj(int n_rurka, int rurka[], int n_krazki, int krazki[])
{
    int ringsInsideCount = 0;

    for (int i = 1; i < n_rurka; i++)
    {
        rurka[i] = min(rurka[i - 1], rurka[i]);
    }

    int j_ring = n_krazki - 1;
    for (int i = n_rurka - 1; i >= 0; i++)
    {
        if (krazki[j_ring] <= rurka[i])
        {
            j_ring--;
            ringsInsideCount++;
            if (j_ring < 0)
                break;
        }
    }

    return ringsInsideCount;
}

int main()
{
    int tubesCount;
    if(!scanf(("%d", &tubesCount))) printf("wrong input");
    int *tubes = (int *)malloc((unsigned)tubesCount * sizeof(int));
    for (int i = 0; i < tubesCount; i++)
    {
        if(!scanf(("%d", &tubes[i]))) printf("wrong input");
    }

    int ringsCount;
    if(!scanf(("%d", &ringsCount))) printf("wrong input");
    int *rings = (int *)malloc((unsigned)ringsCount * sizeof(int));
    for (int i = 0; i < ringsCount; i++)
    {
        if(!scanf(("%d", &rings[i]))) printf("wrong input");
    }

    int ringsFellIntoCount = wrzucaj(tubesCount, tubes, ringsCount, rings);
    printf("%d\n", ringsFellIntoCount);

    free(tubes);
    free(rings);
}