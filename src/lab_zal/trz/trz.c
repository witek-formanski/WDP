#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int closest(int type[], int dist[], int n) { // dany motel ma ten sam indeks w obu tablicach type[] i dist[]
    if (n < 3) return 0;

    int i, j, k = 0; // trzy pointery do gąsiennicy; niezmiennik: n > i >= j >= k >= 0
    int ans = INT_MAX;

    while (type[k] == type[k + 1]) { // pierwszy motel musi być dalej niż inne motele tego typu obok niego
        k++;
        if (k == n - 2) return 0;  // jeśli motele są tylko jednego typu
    }

    j = k + 1;  // pointery muszą wskazywać na motele różnych typów
    i = j + 1;
    while (type[i] == type[j] || type[i] == type[k]) {
        i++;
        if (i == n) return 0; // jeśli motele są tylko dwóch typów
    }

    while (i < n) {
        if (type[j] == type[k]) {
            j++;
            continue;
        }

        if (type[i] == type[j] || type[i] == type[k]) {
            i++;
            continue;
        }

        ans = min(ans, max(dist[i] - dist[j], dist[j] - dist[k]));

        if (j < i && type[j] == type[j + 1]) { // sprawdzenie wszystkich możliwych środkowych moteli przy ustalonych skrajnych
            j++;
            continue;
        }

        k = j;
    }

    return ans;
}

int* get_extremes(int type[], int n) {
    int* extr = (int*)malloc((size_t)6 * sizeof(int));
    extr[0] = 0;
    extr[1] = 1;
    extr[2] = 2;
    extr[3] = n - 3;
    extr[4] = n - 2;
    extr[5] = n - 1;

    while (type[extr[1]] == type[extr[0]]) {
        extr[1]++;
        if (extr[1] == n) return NULL;
    }

    while (type[extr[2]] == type[extr[0]] || type[extr[2]] == type[extr[1]]) {
        extr[2]++;
        if (extr[2] == n) return NULL;
    }

    while (type[extr[4]] == type[extr[5]]) extr[4]--;
    while (type[extr[3]] == type[extr[5]] || type[extr[3]] == type[extr[4]]) extr[3]--;

    return extr;  // 3 pierwsze i 3 ostatnie motele różnych typów
}

int get_overlap(int extr[]) {
    int overlap = 0;

    for (int i = 3; i < 6; i++) {
        if (extr[i] < extr[2]) overlap++;
        else break;
    }

    return overlap;  // jeśli któreś z ostanich skrajnych moteli znajdują się przed skrajnymi pierwszymi
}

int find_farthest_three(int type[], int dist[], int extr[], int overlap) {
    int ans = 0;

    for (int i = extr[0]; i < extr[5]; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 3 + overlap; k < 6; k++)
                if (type[extr[j]] != type[extr[k]] &&
                    type[extr[j]] != type[i] && 
                    type[extr[k]] != type[i])
                    ans = max(ans, 
                        min(dist[i] - dist[extr[j]],
                            dist[extr[k]] - dist[i]));

    free(extr);
    return ans; // 2 skrajne motele i jeden pomiędzy
}

int farthest(int type[], int dist[], int n) {
    if (n < 3) return 0;

    int* extr = get_extremes(type, n);
    return (extr == NULL) ? 0 : find_farthest_three(type, dist, extr, get_overlap(extr));
}

int main() {
    int n;
    if (!scanf("%d", &n)) printf("invalid value");
    int* type = (int*)malloc((size_t)n * sizeof(int));
    int* dist = (int*)malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; i++) {
        if (!scanf("%d", &type[i])) printf("invalid value");
        if (!scanf("%d", &dist[i])) printf("invalid value");
    }

    printf("%d %d", closest(type, dist, n), farthest(type, dist, n));

    free(type);
    free(dist);
}