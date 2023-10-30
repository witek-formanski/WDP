// zad. 5.2. zliczanie

#include <stdio.h>
#include <stdlib.h>

int minimum_of_convex_func(int n, int a[]) {
    int left = 0;
    int right = n - 1;
    int middle;

    // check if the sequence is increasing or decreasing

    // we look for the smallest element greater than 0
    while (left + 1 < right) {
        middle = (left + right) / 2;
        if (a[middle] > a[middle + 1]) {
            left = middle + 1;
        } else  // (v[middle] <= 0)
        {
            right = middle;
        }
    }

    return min(a[left], a[right]);
}

int main() {}