#include <stdio.h>
#include <stdlib.h>

int znajdz(int **tab, int x_size, int y_size, int v)
{
    int x = x_size - 1, y = y_size - 1;
    int c = 0;
    while (x < x_size && y < y_size)
    {
        if (tab[y][x] > v)
        {
            // move left if possible
            if (x > 0)
                x--;
            else
                break;
        }
        else
        {
            if (tab[y][x] == v)
            {
                // found
                ++c;

                // move across if possible
                ++x;
                if (y > 0)
                    --y;
                else
                    break;
            }
            else
            {
                // move up if possible
                if (y > 0)
                    --y;
                else
                    break;
            }
        }
    }
    return c;
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

int main()
{
    int x, y;
    if(!scanf("%d", &x)) printf("wrong input");
    if(!scanf("%d", &y)) printf("wrong input");

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
    printf("%d\n", znajdz(t, x, y, v));
}