#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

// let: a starts at index 0
int *zsumuj(int n, int a[])
{
    int *suffixSum = (int *)calloc((size_t)n, sizeof(int));
    suffixSum[n - 1] = a[n - 1];
    for (int i = n - 1 - 1; i >= 0; i--)
    {
        suffixSum[i] = suffixSum[i + 1] + a[i];
    }

    int *b = (int *)malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= n)
            b[i] = 0;
        else{
            // we start at 0(in task at 1), so we must decrease value by 1
            int movedLeft = a[i]-1;
            b[i] = suffixSum[max(movedLeft,0)];
        }
    }
    return b;
}

int main(){
    int n; if(!scanf("%d", &n)) printf("wrong input");

    int* a = (int*)malloc((size_t)n*sizeof(int));
    for(int i = 0; i<n; i++) if(!scanf("%d",&a[i])) printf("wrong input");

    int* b = zsumuj(n,a);
    for(int i = 0; i<n; i++) printf("%d\n", b[i]);
}