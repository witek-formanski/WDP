/*
    T(n) = O(n^3)
    M(n) = O(n^2)

    wszystkich możliwych wyrażeń nawiasowych jest wykłądniczo wiele (liczba Catalana)

    [+-+-+] = [+][+-+-] + 0 + [+-+][+-] + 0
    [+-+-] = [+][+-+] + 0 + [+-+][+]
    [+-+] = [+][+-]
    [+-] = [+][+]

    [+] = 1
    [-] = 0

    dp[i][j][b] - ile jest poprawnych obnawiasowań segmentu od i do j *(-1)^b
    b \in {0, 1}
    s[i] \in {-1, 1}
*/

#include <algorithm>
#include <cmath>
#include <iostream>

int*** InitArray(int n) {
    int*** dp = new int**[n];
    for (int i = 0; i < n; i++) {
        dp[i] = new int*[n];
        for (int j = 0; j < n; j++)
            dp[i][j] = new int[2]{-1, -1};
    }

    return dp;
}

void Print(int*** dp, int n) {
    for (int b = 0; b <= 1; b++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << dp[i][j][b] << "\t";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
}

void DeleteArray(int*** dp, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            delete[] dp[i][j];
        delete[] dp[i];
    }
}

int Parentheses(int s[], int n, bool debug) {
    int*** dp = InitArray(n);

    for (int i = 0; i < n; i++)
        for (int b = 0; b <= 1; b++)
            dp[i][i][b] = (s[i] == pow(-1, b));

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            for (int b = 0; b <= 1; b++) {
                dp[i][j][b] = 0;
                for (int k = i; k < j; k++)
                    dp[i][j][b] += dp[i][k][b] * dp[k + 1][j][1 - b];
            }
        }
    }

    int correctParenthesesCount = dp[0][n - 1][0];
    if (debug) Print(dp, n);
    DeleteArray(dp, n);

    return correctParenthesesCount;
}

int main() {
    std::cout << Parentheses(new int[5]{1, -1, 1, -1, 1}, 5, true) << "\n";
}