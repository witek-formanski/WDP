#include <algorithm>
#include <iostream>
#include <cmath>

int** get_sum(int mice[], int n) {
    int** sum = new int*[n];
    for (int i = 0; i < n; i++)
        sum[i] = new int[n]{0};

    for (int i = 0; i < n; i++)
        sum[i][i] = mice[i];
    
    for (int length = 2; length < n; length++) {
        for (int i = 0; i < n - length; i++) {
            sum[i][i + length - 1] = sum[i][i+ length - 2] + mice[i + length - 1] - pow(length - 1, 2);
        }
    }

    return sum;
}

int** get_max_in_interval(int** sum, int n) {
    
}


void print(int** tab, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            std::cout << tab[i][j] << "\t";
        std::cout << "\n";
    }
}


int mice_in_the_corridor(int mice[], int n) {

}

int main() {
    // print()
    int* mice = new int[8]{1, 5, 1, 4, 3, 2, 7, 0};
    print(get_sum(mice, 8), 8);

}