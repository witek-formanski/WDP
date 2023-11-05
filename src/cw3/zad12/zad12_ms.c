#include <stdio.h>
#include <stdbool.h>

void swap(int t[], int i, int j)
{
    int a = t[i];
    t[i] = t[j];
    t[j] = a;
}

void mirror(int t[], int l, int r)
{
    while (l < r)
    {
        swap(t, l++, r--);
    }
}

bool next(int a[], int size)
{
    int j = -1;
    for (int i = size - 1 - 1; i >= 0; i--)
    {
        if (a[i] > a[i + 1])
        {
            j = i;
            break;
        }
    }

    if(j == -1){
        mirror(a, 0, size-1);
        return false;
    }
    else{
        int jmin = size-1;
        for(int i = size-1 -1; i>=j; i--){
            if(a[i]<a[j] && a[j] < a[jmin]){
                jmin=i;
            }
        }

        // swap
        swap(a, jmin, j);
        mirror(a, j+1, size-1);
        return true;
    }

}

void print_i(int t[], int n){
        for (int i = 0; i < n; i++)
    {
        printf("%d ", t[i]);
    }
}

int main()
{
    int n;
    if(!scanf("%d", &n)) printf("wrong input");

    int* t = (int*)malloc((unsigned)n * sizeof(int));
    for(int i = 0; i<n; i++){
        if(!scanf("%d", &t[i])) printf("wrong input");
    }

    int i = 0;
    do{
        print_i(t,n);
        printf("\n");
        i++;
    }while(next(t, n));
}