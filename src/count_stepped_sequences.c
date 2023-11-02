#include <stdio.h>
#include <stdlib.h>

int count_stepped_sequences(int n, int t[]) {
    if (n == 0) return 0;

    int *aux = (int *)malloc((size_t)n * sizeof(int));  // auxiliary table
    aux[0] = t[0];                                      // every element stored in aux[] represents the last element of a sequence
    int count = 1;                                      // aux[] count equals to number of stepped sequences
    for (int i = 1; i < n; i++) {
        if (t[i] <= aux[count - 1]) {  // elements in aux[] are sorted in non-increasing order, so aux[count - 1] is the smallest
            aux[count] = t[i];
            count++;
        } else {
            for (int j = 0; j < count; j++) {  // compare, starting from the greatest element in aux[]
                if (t[i] > aux[j]) {
                    aux[j] = t[i];
                    break;
                }
            }
        }
    }

    return count;
}

int main() {
    int n;
    if (!scanf("%d", &n)) printf("invalid value provided");

    int *t = (int *)malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; i++)
        if (!scanf("%d", &t[i])) printf("invalid value provided");

    // int n = 10;
    // int t[10] = {3, 0, 1, 6, 2, 3, 4, 4, 5, 6};

    printf("%d", count_stepped_sequences(n, t));
}