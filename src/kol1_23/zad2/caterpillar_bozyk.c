/*
T(n) = O(n)
M(n) = O(1)
*/

int minn(int a, int b) {
    return (a < b) ? a : b;
}

int fragments_two_ptrs_pio(int t[], int n, int p) {
    int s = 0, ans = n;
    for (int i = 0, j = 0; i < n; ++i) {
        if (t[i] > p) return 0;
        s += t[i];
        while (s > p) {
            s -= t[j];
            ++j;
            ans = minn(ans, i - j + 1);
        }
    }
    return ans;
}

#include <stdio.h>

int main() {
    int t[14] = {4, 8, 5, 0, 1, 20, 12, 8, 6, 15, 11, 15, 4, 7};
    int n = 14;
    int p = 42;

    printf("%d", fragments_two_ptrs_pio(t, n, p));
}