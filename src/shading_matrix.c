#include <stdio.h>
#include <stdlib.h>

int power_of_four(int n) {
    return 1 << (n << 1);
}

int power_of_two(int n) {
    return 1 << n;
}

int** shading_matrix(int k) {  // k >= 0
    int final_size = power_of_two(k);

    int** matrix = (int**)malloc((size_t)final_size * sizeof(int*));
    for (int i = 0; i < final_size; i++)
        matrix[i] = (int*)malloc((size_t)final_size * sizeof(int));

    matrix[0][0] = 0;
    int size = 1;
    int exponent = k - 1;

    while (size < final_size) {
        size *= 2;
        for (int i = 0; i < size / 2; i++)
            for (int j = 0; j < size / 2; j++) {
                matrix[i + size / 2][j + size / 2] = matrix[i][j] + power_of_four(exponent) * 1;
                matrix[i + size / 2][j] = matrix[i][j] + power_of_four(exponent) * 2;
                matrix[i][j + size / 2] = matrix[i][j] + power_of_four(exponent) * 3;
            }

        exponent--;
    }

    return matrix;
}

int main() {
    int k;
    if(!scanf("%d", &k)) printf("invalid value");
    int** matrix = shading_matrix(k);

    for (int y = 0; y < (1 << k); y++) {
        for (int x = 0; x < (1 << k); x++) {
            printf("%d\t", matrix[x][y]);
        }
        printf("\n");
    }
}