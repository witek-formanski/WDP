#include <stdio.h>
#include <stdlib.h>

// https://www.geeksforgeeks.org/find-duplicates-constant-array-elements-0-n-1-o1-space/
int find(int n, int *a)
{
    int p = 0;
    while (p <= n) {
        if (a[p] == -1) {
            p++;
        }
        else {
            if (a[a[p] - 1] == -1) {
                // a[p]-1 was visited
                return a[p];
            }
            else {
                a[p] = a[a[p] - 1];
                // visited
                a[a[p] - 1] = -1;
            }
        }
    }
    // not found
    return -1;
}

int main()
{
    int n;
    if(!scanf(("%d", &n))) printf("wrong input");

    int *t = (int *)malloc((size_t)(n + 1) * sizeof(int));
    for (int i = 0; i < n + 1; i++)
        if(!scanf(("%d", &t[i]))) printf("wrong input");
        
    printf("%d\n", find(n, t));
}