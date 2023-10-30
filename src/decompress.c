#include <stdio.h>
#include <stdlib.h>

// dekompresuj(6, {1, 3, 3, 9, 42, 3}) == {1, 2, 2, 5, 11, 11, 2}
// t nie zawiera zer

int *decompress(int n, int t[]) {}

int compress_number(int i, int k) { return (1 << (i - 1)) * (2 * k - 1); }

int *compress_array(int n, int arr[]) {
    int *compressed_array = (int *)malloc((size_t)n * sizeof(int));
    int index = 0;
    int counter = 1;
    while (index < n) {
        int temp = arr[index];

        index++;
        if (temp == arr[index])
            counter++;
        else  // if (temp !=arr[index])
        {
            int compressed = compress_number(counter, temp);
            // temp = arr[index];
            counter = 1;
        }
    }
}

void print_array(int n, int a[]) {
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");
}

int *get_array(int *n) {
    if (!scanf("%d", n)) printf("invalid value provided");
    int *a = (int *)malloc((size_t)*n * sizeof(int));
    for (int i = 0; i < *n; ++i)
        if (!scanf("%d", &a[i])) printf("invalid value provided");
    return a;
}

int main() {
    int n;
    int *t = get_array(&n);

    print_array(n, decompress(n, t));

    free(t);

    return 0;
}