#include <iostream>
#include <limits.h>
#include <vector>

/**
 * Pomysł: 
 * Zadanie te różni się od zad1 tylko tym że nie chcemy liczyć tego samego nominału pare razy.
 * Możemy więc trzymać tablicę `used` która pamięta czy użyliśmy obecnego nominału do wydania danej reszty.
 */
int banknoty(int kwota, const std::vector<int> &b) {
    std::vector<int> dp(kwota + 1, -1);
    std::vector<bool> used(kwota + 1);

    dp[0] = 0;

    for (int nominał : b) {
        // reset usage for every nominał
        std::fill(used.begin(), used.end(), false);

        for (int k = 1; k <= kwota; k++) {
            int reszta = k - nominał;

            if (reszta < 0 || dp[reszta] == -1)
                continue;

            // only increment number of coins if adding new nominał
            int costIfUsingNominał = dp[reszta] + (used[reszta] ? 0 : 1);

            if (dp[k] == -1 || costIfUsingNominał <= dp[k]) {
                dp[k] = costIfUsingNominał;
                used[k] = true;
            }
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

    std::cout << banknoty(k, coins);
}