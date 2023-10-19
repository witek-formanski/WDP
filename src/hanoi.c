// #include <math.h>

/*
pomysł:
rekurencja
ustaw największy krążek na właściwym miejscu
następnie zredukuj problem do pozostałych krążków

*/

long long int hanoi(int n, int configuration[], int start)
{
    if (n == 0)
        return 0;

    if (start == configuration[0])
        return hanoi(n - 1, configuration + 1, start);

    // przesuń wszystkie mniejsze krążki na inny słupek (2^n -1)
    // przesuń największy krążek na właściwe miejsce (1)
    // rozważ to samo dla kolejnych krążków
    // pow(2, n - 1) = (1 << (n-1))
    return (1 << (n - 1)) + hanoi(n - 1, configuration + 1, 6 - start - configuration[0]);
}

int main()
{
    int n = 7;
    int configuration[] = {2, 1, 1, 3, 1, 2, 2};
    int start = 3;

    return 0;
}