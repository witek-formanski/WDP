#include<stdio.h>
#include<stdlib.h>

int blisko_zera(int v[], int n){
    int l = 0, p = n - 1, m;
    int monotonicznosc = ((v[0] <= v[n - 1]) ? 1 : -1);
    while(l < p){
        m = (l + p) / 2;
        if(v[m] * monotonicznosc < 0)
            l = m + 1;
        else
            p = m;
    }

    if(l > 0 && abs(v[l - 1]) < abs(v[l]))
        return abs(v[l - 1]);
    else
        return abs(v[l]);
}



int main()
{
    //main from zad_ms.c
    int n;
    if(!scanf("%d", &n)) printf("wrong input");
    int *t = (int *)malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        if(!scanf("%d", &t[i])) printf("wrong input");
    }

    int nearestAbsZero = blisko_zera(t, n);
    printf("%d\n", nearestAbsZero);

    free(t);
}
