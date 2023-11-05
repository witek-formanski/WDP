#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// zamienia w tablicy a[] element a[i] miejscami z a[j]

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// odbija lustrzanie segment tablicy a[] od a[l] do a[r] wlacznie

void mirror(int a[], int l, int r) {
    while (l < r) {
        swap(a, l, r);
        ++l;
        --r;
    }
}

// wylicza nastepna (leksykogradicznie) permutacje po zakodowanej przez a[n]
// (jesli a[n] koduje najwieksza permutacje, zwraca pierwsza oraz false przez
// wartosc)

bool nextPerm(int a[], int size) {
    bool last = false;
    int i = size - 1;
    while (i > 0 && a[i - 1] > a[i]) --i;
    if (i == 0)
        last = true;
    else {
        int j = size - 1;
        while (a[j] < a[i - 1]) --j;
        swap(a, i - 1, j);
    }
    mirror(a, i, size - 1);  // odbija rowniez gdy i == 0
    return last;
}

int main(void) {
    int size;
    if(!scanf("%d", &size)) printf("wrong input");

    int* a = (int*)malloc((unsigned)size * sizeof(int));
    for (int i = 0; i < size; ++i) if(!scanf("%d", &a[i])) printf("wrong input");

    bool b = nextPerm(a, size);
    for (int i = 0; i < size; ++i) printf("%d ", a[i]);
    printf("\nLast: %d", b);

    free(a);
    return 0;
}