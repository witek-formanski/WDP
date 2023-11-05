#include <stdio.h>
#include <stdlib.h>

struct ciag
{
    int dl;
    double *el;
    struct ciag* innerSet;
};

struct ciag* calcDifferentialSet(double *t, int n)
{
    int setLength = n - 1;
    double *setBody = (double *)malloc((unsigned)setLength * sizeof(double));
    for (int i = 1; i < n; i++)
    {
        setBody[i - 1] = t[i] - t[i - 1];
    }
   struct ciag* differentialSet = malloc(sizeof(int) + sizeof(double*)) + sizeof(struct ciag*));
   differentialSet->dl = setLength;
   differentialSet->el = setBody;
    if (differentialSet->dl > 0)
    {
        differentialSet->innerSet = calcDifferentialSet(differentialSet->el, differentialSet->dl);
    }

    return differentialSet;
}

void print_i(double t[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        printf("%lf, ", t[i]);
    }
    printf("%lf", t[n-1]);
}

int main()
{
    int n;
    if(!scanf(("%d", &n))) printf("wrong input");

    double *t = (double *)malloc((unsigned)n * sizeof(double));
    for (int i = 0; i < n; i++)
    {
        if(!scanf(("%lf", &t[i]))) printf("wrong input");
    }

    struct ciag* differentialSet = calcDifferentialSet(t, n);
    do
    {
        printf("%d   (", differentialSet->dl);
        print_i(differentialSet->el, differentialSet->dl);
        printf(")\n");
        differentialSet = differentialSet->innerSet;
    }while(differentialSet->dl>0);
}