/*
T(n) = O(n)
M(n) = O(1)
*/

int minn(int a, int b) {
    return (a < b) ? a : b;
}

int fragments_two_pointers(int t[], int n, int p) {
    int i = 0;
    int j = 0;
    int k = n;
    int sum = t[0];
    int count;
    int k_min;
    int k_max;

    while (j != n) {
        if (sum <= p) {
            count = j - i + 1;
            j++;
            sum += t[j];
        } else {
            k = minn(k, count);
            sum -= t[i];
            i++;
        }
    }

    return k;
}

#include <stdio.h>

int main() {
    int t[14] = {4, 8, 5, 0, 1, 20, 12, 8, 6, 15, 11, 15, 4, 7};
    int n = 14;
    int p = 42;

    printf("%d", fragments_two_pointers(t, n, p));
}