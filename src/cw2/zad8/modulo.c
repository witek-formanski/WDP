// zad. 8
#include <stdio.h>

int does_root_exist(int n) {
    for (int k = 2; k < n / 2; k++) {
        if (k * k % n == 1) return 1;
    }

    return 0;
}

int main() {
    int n;
    if(!scanf("%d", &n)) printf("wrong input");

    printf("%d", does_root_exist(n));
    return 0;
}