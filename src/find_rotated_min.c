// zad. 11 zliczanie

// jeśli tablica była rotowana o liczbę pozycji różną od 0,
// to a[n-1] < a[0]

int find_index_of_minimum(int *a, int n) {
    if (a[0] < a[n - 1]) return 0;

    int l = 0;
    int r = n - 1;
    int m;

    while (l < r) {
        m = (l + r) / 2;
        if (a[m] > a[l])
            l = m + 1;
        else
            r = m;
    }

    return l;
}