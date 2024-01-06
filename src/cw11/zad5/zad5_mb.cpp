#include <iostream>
#include <limits.h>
#include <vector>

int unikat(const std::vector<int> &b, int kwota) {
    std::vector<int> dp(kwota + 1);

    dp[0] = 1;

    // liczymy na ile sposobów da się wydać daną kwotę
    for (int nominał : b) {
        for (int k = 1; k <= kwota; k++) {
            int reszta = k - nominał;

            // skip jeżeli moneta jest większa niż kwota, lub jeżeli nie da się uzyskać reszty
            if (reszta < 0 || dp[reszta] == 0)
                continue;

            dp[k] += dp[reszta];
        }
    }

    // znajdź największą kwotę
    for (int k = kwota; k >= 0; k--)
        if (dp[k] == 1)
            return k;

    return -1;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> coins(n);
    for (int i = 0; i < n; i++)
        std::cin >> coins[i];

    int k;
    std::cin >> k;

    std::cout << unikat(coins, k);
}