#include <stdio.h>
#include <stdlib.h>

void print2D(int **a, int x, int y)
{
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int border_length(int xs, int ys, int xe, int ye)
{
    return 2 * (xe - xs + 1 + ye - ys + 1);
}

int count_trees(int **a, int xs, int ys, int xe, int ye)
{
    int treesCount = a[ye][xe];
    int leftTopSubstracted = 0;
    if (ys > 0)
    {
        // substract trees above
        treesCount -= a[ys - 1][xe];
        ++leftTopSubstracted;
    }
    if (xs > 0)
    {
        // substract trees on the left
        treesCount -= a[ye][xe - 1];
        ++leftTopSubstracted;
    }
    // if left top rectangle was substracted twice, it should be corrected
    if (leftTopSubstracted == 2)
    {
        treesCount += a[ys - 1][xs - 1];
    }
    return treesCount;
}

int **allocate2DArray(int x, int y)
{
    int **t = (int **)malloc((size_t)y * sizeof(int *));
    for (int i = 0; i < y; i++)
    {
        t[i] = (int *)malloc((size_t)x * sizeof(int));
    }
    return t;
}

int **sumTrees(int **a, int x, int y)
{
    int **tab_sum = allocate2DArray(x, y);
    tab_sum[0][0] = a[0][0];
    for (int i = 1; i < x; i++)
    {
        tab_sum[0][i] = tab_sum[0][i - 1] + a[0][i];
    }
    for (int ys = 1; ys < y; ys++)
    {
        tab_sum[ys][0] = tab_sum[ys - 1][0] + a[ys][0];
        for (int xs = 1; xs < x; xs++)
        {
            tab_sum[ys][xs] = tab_sum[ys - 1][xs] + a[ys][xs] + tab_sum[ys][xs - 1] - tab_sum[ys - 1][xs - 1];
        }
    }
    return tab_sum;
}

int prostokat2(int **a, int x, int y, int k)
{
    int minBorder = 2 * (x + 1 + y + 1);
    int **tab_sum = sumTrees(a, x, y);

    for (int xs = 0; xs < x; xs++)
    {
        for (int xe = xs; xe < x; xe++)
        {
            int ys = 0, ye = 0;
            while (ye < y && ys <= ye)
            {
                int border = border_length(xs, ys, xe, ye);
                if (border > minBorder)
                    ys++;

                int treesInside = count_trees(tab_sum, xs, ys, xe, ye);
                if (treesInside >= k)
                {
                    if (border < minBorder)
                        minBorder = border;
                    if (treesInside > k)
                        ys++;
                    else
                        ye++;
                }
                else
                {
                    ye++;
                }
            }
        }
    }
    return minBorder;
}

// static int k, m;
int prostokąt(int **a, int x, int y, int k)
{
    // k = 0;
    // m = 0;
    int minBorder = 2 * (x + 1 + y + 1);
    int **tab_sum = sumTrees(a, x, y);

    for (int ys = 0; ys < y; ys++)
    {
        for (int xs = 0; xs < x; xs++)
        {
            for (int xe = xs; xe < x; xe++)
            {
                for (int ye = ys; ye < y; ye++)
                {
                    int border = border_length(xs, ys, xe, ye);
                    if (border > minBorder)
                        break;

                    int trees = count_trees(tab_sum, xs, ys, xe, ye);
                    if (trees >= k)
                    {
                        if (border < minBorder)
                        {
                            minBorder = border;
                        }
                        break;
                    }
                }
            }
            // for (int ly = 0; ly + ys < y && ly < minBorder; ly++)
            // {
            //     for (int lx = 0; lx + xs < x && lx < minBorder; lx++)
            //     {
            //         ++k;
            //         int xe = xs + lx, ye = ys + ly;

            //         int border = border_length(xs, ys, xe, ye);
            //         if (border > minBorder)
            //         {
            //             break;
            //         }
            //         ++m;

            //         int trees = count_trees(tab_sum, xs, ys, xe, ye);
            //         if (trees >= k)
            //         {
            //             if (border < minBorder)
            //             {
            //                 minBorder = border;
            //             }
            //         }
            //     }
            // }
        }
    }

    // printf("k: %d m: %d\n", k, m);
    return minBorder;
}

int main()
{
    int x, y;
    if(!scanf("%d", &y)) printf("wrong input");
    if(!scanf("%d", &x)) printf("wrong input");

    int **t = allocate2DArray(x, y);
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if(!scanf("%d", &t[i][j])) printf("wrong input");
        }
    }
    int v;
    if(!scanf("%d", &v)) printf("wrong input");
    printf("%d\n", prostokat2(t, x, y, v));
}