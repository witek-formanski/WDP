// iterujemy po elementach a[]
// skaczemy do tego indeksu, jaką wartość odwiedziliśmy
// element, do którego przeskoczyliśmy:
// - albo mnożymy razy -1
// - albo odejmujemy od niego n
// jeżeli element, do którego wskoczyliśmy jest ujemny, znaleźliśmy duplikat

#include <stdio.h>
#include <stdlib.h>

// size(a) = n + 1
// a[] zawiera elementy od 1 do n
int find_duplicate(int n, int a[]) {
    int i = 0;
    int counter = 0;
    while (counter < n + 1) {
        if (a[i] < 0)
            return -a[i];

        a[i] *= (-1);
        i = -a[i];
        counter++;
    }

    return -1;
}

int main() {
    int n;
    if (!scanf("%d", &n), printf("invalid value\n"));

    int *a = (int *)malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; i++)
        if (!scanf("%d", &a[i]), printf("invalid value\n"));

    printf("%d", find_duplicate(n, a));

    return 0;
}