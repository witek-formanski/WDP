/*
1 2 3 3 3 4 5 7
0 1 1 2 4 5 5

i = 0
j = 1
*/

#include <stdio.h>

void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void swap2(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void increment(int *i, int a[], int *counter) {
    if (a[*i] == a[++(*i)])
        *counter++;
}

int count_duplicates(int a[], int n, int b[], int m) {
    int i = 0;
    int j = 0;
    int counter = 0;

    while (i < n && j < n) {
        if (b[j] < a[i])
            increment(&j, b, &counter);
        else if (b[j] == a[i]) {
            counter++;
            increment(&i, a, &counter);
            increment(&j, b, &counter);
        } else
            increment(&i, a, &counter);
    }
}

int count_distinct(int a[], int n, int b[], int m) {
    return n + m - count_duplicates(a, n, b, m);
}

int main() {
    int a = 2137;
    int b = 42;

    swap(&a, &b);

    printf("%d\n", a);
    printf("%d\n", b);
}