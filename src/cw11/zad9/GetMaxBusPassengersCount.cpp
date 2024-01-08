/*
    T(n, m) = O(n * m)
    M(n, m) = O(n * m)
*/

#include <algorithm>
#include <iostream>

int GetMaxBusPassengersCount(int** city, int n, int m) {
    int** dp = new int*[n];
    for (int i = 0; i < n; i++)
        dp[i] = new int[m];

    int i, j;
    dp[0][0] = city[0][0];
    for (int i = 1; i < n; i++)
        dp[i][0] = city[i][0] + dp[i - 1][0];
    for (int j = 1; j < m; j++)
        dp[0][j] = city[0][j] + dp[0][j - 1];

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            dp[i][j] = city[i][j] + std::max(dp[i - 1][j], dp[i][j - 1]);

    return dp[n - 1][m - 1];
}

int main() {
    int arr[6][3] = {
        {0, 10, 0},
        {8, 0, 0},
        {0, 5, 4},
        {0, 0, 0},
        {0, 2, 0},
        {1, 0, 0},
    };

    int** ptr = new int*[6];
    for (int i = 0; i < 6; ++i)
        ptr[i] = arr[i];

    std::cout << GetMaxBusPassengersCount(ptr, 6, 3);
    
    delete[] ptr;
}