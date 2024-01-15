/*
nieparzysta liczba nawiasów => -1 (nie da się)
parzysta liczba nawisów:
suma prefiksowa (+1 za "(", -1 za ")")
docelowo nigdy nie możemy zejść poniżej 0

l to ostatnia wartość w tablicy prefiksowej
k to maksymalna "głębokość" poniżej osi (-k to min z tablicy prefiksowej)
musimy wykonać sufit z k/2 obróceń od lewej (")" -> "("), żeby nic nie było pod osią
potem musimy wykonać (l + 2suf(k/2))/2 = l/2 + suf(k/2) kroków, żeby ostatnia wartość wynosiła 0
czyli ostatecznie odpowiedź to l/2 + 2sufit(k/2)
jeżeli k jest ujemne (-k dodatnie), to pomijamy (czyli odp to l/2)
*/

/*
parentheses:
( -> 1
) -> -1
*/

/*
    T(n) = O(n)
    M(n) = O(n) (można O(1))
*/

#include <algorithm>

int* get_prefix_tab(int parentheses[], int size) {
    int* prefix_tab = new int[size];
    prefix_tab[0] = parentheses[0];
    for (int i = 1; i < size; i++)
        prefix_tab[i] = prefix_tab[i - 1] + parentheses[i];
    
    return prefix_tab;
}

int get_minimum(int prefix_tab[], int size) {
    int minimum = 0;
    for (int i = 0; i < size; i++)
        minimum = std::min(minimum, prefix_tab[i]);
}

int rotate_parentheses(int parentheses[], int size) {
    if (size % 2)
        return -1;
    
    int* prefix_tab = get_prefix_tab(parentheses, size);
    int minus_k = get_minimum(prefix_tab, size);
    int l = prefix_tab[size - 1];
    delete[] prefix_tab;

    return l/2 + 2 * ((-minus_k+1) / 2);
}