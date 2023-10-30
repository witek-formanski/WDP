#include <stdio.h>
#include <stdlib.h>

// wynajduje wszystkie prefiksy bedace permutacjami swoich indeksow

int* podziel(int n, int a[]) {
    int* p = (int*)malloc((unsigned)n * sizeof(int));
    int l = 0;  // lewy koniec przegladanego cyklu
    int r = 0;  // prawy koniec przegladanego cyklu
    int i = 0;  // liczba znalezionych punktow podzialu
    int c = 0;  // indeks przegladajacy cykl
    while (l < n) {
        if (a[l] < 0) {  // jesli byl odwiedzony...
            a[l] += n;   // ...to przywracamy wartosc i idziemy dalej
            ++l;
        } else {  // jesli nie byl odwiedzony...
            c = a[l];
            r = c;
            a[l] -= n;  // oznaczamy jako odwiedzony
            while (a[c] > 0) {
                a[c] -= n;  // oznaczamy jako odwiedzony
                c = n + a[c];
                if (c > r) r = c;
            }
            if (i == 0 || r > p[i - 1]) {
                p[i] = r;
                ++i;
            }
        }
    }
    return p;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int* a = (int*)malloc((unsigned)n * sizeof(int));
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int* p = podziel(n, a);
    for (int i = 0; p[i] < n - 1; ++i) printf("%d ", p[i]);
    printf("%d\n", n - 1);
    free(p);
    return 0;
}