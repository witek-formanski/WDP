#include <stdio.h>
#include <stdlib.h>

unsigned long long int power2(int n, int k)
{
    unsigned long long int ret = 1;
    for (int i = 0; i < k; i++)
        ret *= n;
    return ret;
}

void print_shadow(unsigned long long int **t, unsigned long long int k)
{
    unsigned long long int n = power2(2, k);
    for (unsigned long long int i = 0; i < n; i++)
    {
        for (unsigned long long int j = 0; j < n; j++)
        {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

static unsigned long long int it = 0;
static unsigned long long int it2 = 0;

unsigned long long int fill(unsigned long long int **tab, unsigned long long int x, unsigned long long int y, unsigned long long int side, int r)
{
    for (int ys = 0; ys < side; ys++)
    {
        for (int xs = 0; xs < side; xs++)
        {
            tab[ys + y][xs + x] = (4 * tab[ys][xs]) + r;
            it++;
        }
    }
}

void shadow(unsigned long long int **tab, int currSize, int currK, int k)
{
    it2++;

    if (currK == 0)
    {
        tab[0][0] = 0;
        it++;
    }
    else
    {
        int half = currSize / 2;
        // right top
        fill(tab, half, 0, half, 2);
        // right bottom
        fill(tab, half, half, half, 1);
        // left bottom
        fill(tab, 0, half, half, 3);
        // left top
        fill(tab, 0, 0, half, 0);
    }

    // printf("K%d: \n", currK);
    // print_shadow(tab, currK);
    if (currK == k)
        return;
    shadow(tab, currSize * 2, currK + 1, k);
}

void shadow2(unsigned long long int **tab, int currSize, int currK)
{
    if (currK == 0)
    {
        tab[0][0] = 0;
        it++;
        return;
    }
    shadow2(tab, currSize / 2, currK - 1);
    int half = currSize / 2;

    // print_shadow(tab, currK);
    fill(tab, half, 0, half, 2);
    // print_shadow(tab, currK);
    fill(tab, half, half, half, 1);
    // print_shadow(tab, currK);
    fill(tab, 0, half, half, 3);
        fill(tab, 0, 0, half, 0);
    // print_shadow(tab, currK);
}

unsigned long long int **cieniowanie(int k)
{
    it = 0;
    it2=0;
    unsigned long long int side = power2(2, k);
    unsigned long long int **t = (unsigned long long int **)malloc(sizeof(unsigned long long int *) * ((size_t)side));
    for (int i = 0; i < side; i++)
    {
        t[i] = (unsigned long long int *)malloc((size_t)side * sizeof(unsigned long long int));
    }

    shadow(t, 1, 0, k);
    return t;
}

unsigned long long int **cieniowanie2(int k)
{
    it = 0;
    unsigned long long int side = power2(2, k);
    unsigned long long int **t = (unsigned long long int **)malloc(sizeof(unsigned long long int *) * ((size_t)side));
    for (int i = 0; i < side; i++)
    {
        t[i] = (unsigned long long int *)malloc((size_t)side * sizeof(unsigned long long int));
    }

    shadow2(t, side, k);
    return t;
}

unsigned long long int** shadowWithStats(int k){
    unsigned long long int **shad = cieniowanie2(k);
    //print_shadow(shad, k);
    unsigned long long int shouldBe = k * power2(2, 2*k);
    double faster = ((double)shouldBe)/it;
    printf("%d: %d | %d - %fx faster\n", k, it, shouldBe,faster);

    return shad;
}

int main()
{
    // int n;
    // scanf("%d", &n);
    // shadowWithStats(n);

    // int **shad = cieniowanie(n);
    // print_shadow(shad, n);
    // int shouldBe = n * power2(2, 2*n);
    // printf("%d: %d | %d\n", n, it, shouldBe);

    print_shadow(shadowWithStats(13),13);

    // for (int k = 0; k <= 13; k++)
    // {
    //     unsigned long long int** tb = shadowWithStats(k);
    //     print_shadow(tb, k);
    // }
}