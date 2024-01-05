#include <iostream>
#include <vector>

int minMonet(int kwota, std::vector<int> &monety) {
    std::vector<int> dp(kwota + 1);

    dp[0] = 1;

    for (int nominał : monety) {
        for (int k = 1; k <= kwota; k++) {
            int reszta = k - nominał;

            // skip jeżeli moneta jest większa niż kwota, lub jeżeli nie da się uzyskać reszty
            if (reszta < 0 || dp[reszta] == 0)
                continue;

            dp[k] += dp[reszta];
        }
    }

    return dp[kwota];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> coins(n);
    for (int i = 0; i < n; i++)
        std::cin >> coins[i];

    int k;
    std::cin >> k;

    std::cout << minMonet(k, coins);
}