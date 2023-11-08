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
    int i_a;           // = n - 3;
    int i_b;           // = n - 2;

    for (int i_c = n - 1; i_c > 1; i_c--) {
        distance = 0;

        c = t[i_c];
        b = t[i_c - 1];
        a = t[i_c - 2];

        i_b = i_c - 1;
        i_a = i_c - 2;

        while (c < a + b && i_a >= 0) {
            counter += distance + 1;

            if (i_b - i_a > 1) {
                i_b--;
                b = t[i_b];
                distance++;
            } else {
                if (i_a == 0) 
                    break;

                i_a--;
                a = t[i_a];
            }
        }
    }

    return counter;
}

int main() {}