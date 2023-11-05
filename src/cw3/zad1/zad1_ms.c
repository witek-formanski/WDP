#include <stdio.h>
#include <stdlib.h>

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

// Original task [PL]
// Napisz funkcję void rotate(int n, int t[], int k), która dokona rotacji cyklicznej tablicy t
// (zawierającej n liczb całkowitych) w prawo o k pozycji. Twoje rozwiązanie nie powinno
// korzystać z żadnych dodatkowych tablic pomocniczych. Parametr k może mieć dowolną wartość.
// W szczególności k < 0 powinno spowodować rotację cykliczną tablicy w lewo. 

// What does it do
// Cyclical rotate array by k (move each element by k) to the right
// obviously, for k<0 elements will be moved into left
// task forbids creating another array
void rotate(int n, int t[], int k)
{
    k = k % n;
    if (k < 0)
    {
        k += n;
    }

    mirror(t, 0, n - k - 1);
    mirror(t, n - k, n - 1);
    mirror(t, 0, n - 1);
}

void print_t(int t[], int n){
        for (int i = 0; i < n; i++)
    {
        printf("%d\n", t[i]);
    }
}

int main()
{
    int n;
    if(!scanf("%d", &n)) printf("wrong input");

    int *t = (int*)malloc((size_t)(n * (int)sizeof(int)));
    for (int i = 0; i < n; i++)
    {
        if(!scanf("%d", &t[i])) printf("wrong input");
    }

    int k;
    if(!scanf("%d", &k)) printf("wrong input");

    rotate(n, t, k);
    print_t(t,n);
}