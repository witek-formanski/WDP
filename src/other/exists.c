#include <stdbool.h>
#include <stdlib.h>

/*
@brief
sprawdza, czy istnieje taki indeks i,
że A[i] == A[N - 1 - i]
@params
int A[] - tablica zawierająca dwa podciągi rosnące
- jeden na indeksach parzystych, drugi na nieparzystych
@returns
true jeśli istnieje indeks spełniający warunek
*/
bool exists(int A[], int N) {
    // jeżeli N nieparzyste, to i = (N-1)/2 spełnia
    if (N % 2 == 1) return true;

    // N parzyste (N - 1 nieparzyste) => i musi być parzyste
    // szukam kandydata i/2
    int l = 0;
    int r = N / 2 - 1;
    int m;
    while (l < r) {
        m = (l + r) / 2 + 1;
        if (A[2 * m] < A[N - 1 - 2 * m])
            l = m;
        else if (A[2 * m] == A[N - 1 - 2 * m])
            return true;
        else
            r = m - 1;
    }
    
    return false;
}

#include <stdio.h>

int main() {
    int tab_true[6] = {1, 0, 2, 2, 3, 5};
    int tab_false[6] = {1, 2, 2, 4, 3, 5};
    printf("%d\n%d", exists(tab_true, 6), exists(tab_false, 6));
}