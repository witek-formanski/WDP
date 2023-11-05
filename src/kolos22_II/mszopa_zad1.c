#include <stdio.h>
#include <stdlib.h>

void print_tab(int *t, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", t[i]);
    }
    printf("%d", t[n - 1]);
    printf("\n");
}

int winner(int x, int y)
{
    if (x == y)
        return x - 1;
    return x + y - 1;
}

int *rm(int *t, int n, int v)
{
    int *newT = (int *)malloc((size_t)(n - 1) * sizeof(int));

    int currI = 0;

    for (int i = 2; i < n; i++)
    {
        if (v > 0 && v <= t[i])
        {
            newT[currI++] = v;
            i--;
            v = 0;
        }
        else
            newT[currI++] = t[i];
    }
    if (v > 0)
    {
        newT[(n - 1) - 1] = v;
    }
    free(t);
    return newT;
}

// int robolak(int **r, int *n)
// {
//     int left = -1;
//     while (*n > 1)
//     {
//         printf("%d | ", left);
//         print_tab(*r, *n);
//         if (left <= (*r)[1])
//         {
//             if (left == -1)
//             {
//                 left = winner((*r)[0], (*r)[1]);

//                 (*n) -= 2;
//                 (*r) += 2;
//             }
//             else
//             {
//                 left = winner((*r)[0], left);
//                 (*n)--;
//                 ++(*r);
//             }
//         }
//         else
//         {
//             int nLeft = robolak(r, n);
//         }
//     }
//     if(left!=-1){
//         printf("%d %d\n", left, (*r)[0]);
//         return winner(left, (*r)[0]);
//     }
//     return (*r)[0];
// }

int min(int a, int b)
{
    if (b < a)
        return min(b, a);
    if (a == -1)
        return b;
    return a;
}

void robolak2(int **r, int *n, int left)
{
    while (*n > 1 || (*r)[0] <= left)
    {
        print_tab(*r, *n);
        if (left == -1)
        {
            left = (*r)[0];
            ++(*r);
            --(*n);
        }

        if (left <= (*r)[1])
        {
            int w = winner(left, (*r)[0]);

            if (w <= (*r)[1])
            {
                (*r)[0] = w;
                left = -1;
            }
            else
            {
                ++(*r);
                --(*n);
                robolak2(r, n, w);
            }
        }
        else
        {
            robolak2(r, n, left);
        }
    }
}

int robakolak(int *r, int n)
{
    robolak2(&r, &n, -1);
    return r[0];
}

int main()
{
    int n;
    scanf("%d", &n);
    int *t = (int *)malloc((size_t)n * sizeof(n));
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);

    printf("%d\n", robakolak(t, n));
}