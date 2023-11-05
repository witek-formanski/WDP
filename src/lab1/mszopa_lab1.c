#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    scanf("%d", &n);

    int* t = malloc((size_t)(n * (int)sizeof(int)));
    for (int i = n - 1; i >= 0; i--) {
        scanf("%d", &t[i]);
    }

    int max_length = 0;

    int act_length = 1;
    int j = 0;

    for (int i = 1; i < n; i++) {
        if (t[i] != 0 && t[j] % t[i] == 0) {
            act_length++;
        }
        else {
            // skip unrelevant elems
            j = i;

            if (act_length > max_length) {
                max_length = act_length;
            }
            act_length = 1;
        }
    }

    if (act_length > max_length) {
        max_length = act_length;
    }

   printf("%d\n", max_length);
} 
