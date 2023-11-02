#include <stdio.h>
#include <stdlib.h>

// zwraca min(a,b)
int minimum(int a, int b) { return a < b ? a : b; }

// zwraca liczbe roznych elementow w niemalejacej a[n]
int distinct(int n, int a[]) {
    int count = 0;
    if (n) {
        int val = a[0];
        ++count;
        for (int i = 1; i < n; ++i) {
            if (a[i] != val) {
                val = a[i];
                ++count;
            }
        }
    }
    return count;
}

// zwraca liczbe roznych elementow w sumie a[n] oraz b[m]
// przy zalozeniu, ze na wejscie sa posortowane niemalejaco
int countDistinct(int n, int a[], int m, int b[]) {
    if (!n) return distinct(m, b);
    if (!m) return distinct(n, a);
    int val = minimum(a[0], b[0]);  // m, n > 0
    int i = 0, j = 0;
    while (a[i] == val) ++i;
    while (b[j] == val) ++j;
    return 1 + countDistinct(n - i, a + i, m - j, b + j);
}

/*** rzeczy do testow ***/

// wczytaj tablice
int* getArray(int n) {
    int* s = (int*)malloc((unsigned)n * sizeof(int));
    for (int i = 0; i < n; ++i) scanf("%d", s + i);
    return s;
}

int main(void) {
    // wczytaj n i a[n]
    int n;
    scanf("%d", &n);
    int* a = getArray(n);

    // wczytaj m i b[m]
    int m;
    scanf("%d", &m);
    int* b = getArray(m);

    // licz moc sumy
    printf("%d\n", countDistinct(n, a, m, b));

    free(a);
    free(b);

    return 0;
}