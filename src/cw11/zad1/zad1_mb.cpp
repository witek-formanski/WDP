#include <algorithm>
#include <iostream>
#include <vector>

int minMonet(int kwota, std::vector<int> &monety) {
    //-1 - nie da się uzyskać kwoty
    std::vector<int> dp(kwota + 1, -1);

    dp[0] = 0;

    for (int nominał : monety) {
        for (int k = 1; k <= kwota; k++) {
            int reszta = k - nominał;

            if (reszta < 0 || dp[reszta] == -1)
                continue;

            if (dp[k] == -1)
                dp[k] = dp[reszta] + 1;
            else
                dp[k] = std::min(dp[k], dp[reszta] + 1);
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