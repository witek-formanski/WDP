#include <stdio.h>
#include <stdlib.h>

// tab - all elements sorted in ascending order
// a < b < c
// c < a + b

// T(n) = O(n^2)
// M(n) = O(1)

int trojki(int n, int t[]) {
    int a, b, c;
    int counter = 0;
    int distance;  // index(c) - index(b) - 1
    int i_a;       // = 0;
    int i_b;       // = n - 2;
    int i_c;       // = n - 1;

    a = t[0];
    b = t[n - 2];
    c = t[n - 1];

    i_a++;
    a = t[i_a];
    if (c < a + b) {
        // działa też dla wszystkich a mniejszych od obecnego b
    }

    // b działa
    // schodzimy b w dół i szukamy pierwszego b, które nie działa
    // gdy znajdziemy pierwsze takie b:
    // - doliczamy wszystkie pary a i b takie że:
    //    - b > b_current
    //    - a >= a_current && a < b
    // == suma(  i_b + 1 - i_a aż do i_c - 1  )
    // int sum = 0;
    // for (int i = i_b + 1 - i_a; i <= i_c - 1; i++) {
    //     sum += i;
    // }

    int sum = (i_b - i_a + i_c) * (i_c - i_b - 1) / 2;

    return counter;
}

int main() {}