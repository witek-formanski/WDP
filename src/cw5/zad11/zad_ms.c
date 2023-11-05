#include <stdio.h>
#include <stdlib.h>

int find(int arr[], int size)
{
    if (size == 1)
        return 0;
    if (arr[0] < arr[size - 1])
        return 0;

    int l = 0, p = size - 1;
    while (l < p)
    {
        int pivot = (l+p)/2;
        if(arr[pivot]<arr[p]){
            p = pivot;
        }
        else{
            l = pivot+1;
        }
    }
    return l;
}

int main(){
    int n;
    if(!scanf(("%d", &n))) printf("wrong input");

    int *t = (int*)malloc((size_t)n*sizeof(int));

    for (int i = 0; i < n; i++)
    {
        if(!scanf(("%d", &t[i]))) printf("wrong input");
    }

    printf("%d\n", find(t,n));
}