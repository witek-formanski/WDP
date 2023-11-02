/*
jeśli wypisujemy ruchy, to złożoność wynosi:
omega(n), O(2^n)
*/

void print_hanoi(int n, int configuration[], int start) {
    if (n == 0) return;

    if (start == configuration[0]) print_hanoi(n - 1, configuration + 1, start);

    // wypisz przesuwanie całej wieży na słupek nr 6 - start - configuration[0]
    // wypisz przesuwanie największego krążka na słupek configuration[0]
    print_hanoi(n - 1, configuration + 1, 6 - start - configuration[0]);
}