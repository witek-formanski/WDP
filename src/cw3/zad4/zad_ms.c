#include <stdio.h>
#include <stdlib.h>

int *bonifacy_template(int n)
{
    int *template = (int *)calloc((size_t)n, sizeof(int));
    if (n == 0)
        return template;
    template[0] = 0;
    if (n == 1)
        return template;
    template[1] = 1;
    if (n == 2)
        return template;
    template[2] = 1;

    return template;
}

static int *bonifacyArray;

int bonifacy_r(int n, int k, int *b)
{
    if (n >= 3 && bonifacyArray[n] == 0)
    {
        if (b[n % k] == 0)
        {
            bonifacyArray[n] = bonifacy_r(n - 1, k, b) + bonifacy_r(n - 2, k, b);
        }
        else
        {
            bonifacyArray[n] = bonifacy_r(n - 1, k, b) + bonifacy_r(n - 3, k, b);
        }
    }
    return bonifacyArray[n];
}

int bonifacy(int n, int k, int *b)
{
    bonifacyArray = bonifacy_template(n + 1);
    int bn= bonifacy_r(n, k, b);
    return bn;
}

int main()
{
    int n;
    if(!scanf("%d", &n)) printf("wrong input");

    int k;
    if(!scanf("%d", &k)) printf("wrong input");
    int *b = (int *)malloc((size_t)k * sizeof(int));
    for (int i = 0; i < k; i++)
    {
        if(!scanf("%d", &b[i])) printf("wrong input");
    }

    int bonifacyN = bonifacy(n, k, b);
    printf("%d\n", bonifacyN);
}