#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j <= high; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int index = partition(arr, low, high);

        quick_sort(arr, low, index - 1);
        quick_sort(arr, index + 1, high);
    }
}

// check if b[] contains all elements of a[]
bool is_subsequence(int a[], int size_a, int b[], int size_b) {
    quick_sort(a, 0, size_a);
    quick_sort(b, 0, size_b);

    int j = 0;
    for (int i = 0; i < size_a; i++) {
        if (a[i] < b[i])
            return false;
        else if (a[i] > b[i])
            i--;
        
        j++;

        if (j == size_b)
            return false;
    }

    return true;
}

int main() {
    int size_a, size_b;
    if(!scanf("%d", &size_a)) printf("invalid value");
    int* a = (int*)malloc((size_t)size_a * sizeof(int));
    for (int i = 0; i < size_a; i++) {
        if(!scanf("%d", &a[i])) printf("invalid value");
    }

    if(!scanf("%d", &size_b)) printf("invalid value");
    int* b = (int*)malloc((size_t)size_b * sizeof(int));
    for (int i = 0; i < size_b; i++) {
        if(!scanf("%d", &b[i])) printf("invalid value");
    }

    printf("%d", is_subsequence(a, size_a, b, size_b));
}