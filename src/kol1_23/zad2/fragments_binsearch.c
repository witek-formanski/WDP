/*
T(n) = O(nlogn)
M(n) = O(1)
*/

#include <stdbool.h>

bool not_exceeds(int t[], int n, int p, int k) {
    if (k == 0)
        return true;

    int sum = 0;
    for (int i = 0; i < k - 1; i++)
        sum += t[i];

    for (int i = k; i < n + 1; i++) {
        sum += t[i - 1];
        if (sum > p)
            return false;
        sum -= t[i - k];
    }

    return true;
}

int fragments_binsearch(int t[], int n, int p) {
    int l = 1;
    int r = n;
    int m;  // k
    while (l < r) {
        m = (l + r) / 2 + 1;
        if (not_exceeds(t, n, p, m))
            l = m;
        else
            r = m - 1;
    }

    return l;
}

#include <stdio.h>

int main() {
    int t[14] = {4, 8, 5, 0, 1, 20, 12, 8, 6, 15, 11, 15, 4, 7};
    int n = 14;
    int p = 42;

    printf("%d", fragments_binsearch(t, n, p));
}