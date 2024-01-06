#include <iostream>
#include <limits.h>
#include <vector>

int banknoty(int kwota, const std::vector<int> &b, const std::vector<int> &c) {
    // dp[i][k] i - ile banknotów, k - kwota
    std::vector<std::vector<int>> dp(b.size() + 1, std::vector<int>(kwota + 1, -1));

    // zero zawsze można uzyskać za pomocą zero banknotów
    for (size_t i = 0; i < dp.size(); i++)
        dp[i][0] = 0;

    // iterujemy przez banknoty
    for (size_t i = 1; i <= b.size(); i++) {
        int nominał = b[i - 1];
        int ileDostępnych = c[i - 1];

        // iterujemy przez kwoty
        for (int k = 1; k <= kwota; k++) {

            // not adding any banknoty
            dp[i][k] = dp[i - 1][k];

            // adding 1 or more banknoty
            for (int ile = 1; ile <= ileDostępnych; ile++) {
                int reszta = k - nominał * ile;

                if (reszta < 0)
                    break;

                // nie da się wypłacić reszty
                if (dp[i - 1][reszta] == -1)
                    continue;

                int nowaIlość = dp[i - 1][reszta] + ile;

                if (dp[i][k] == -1 || nowaIlość < dp[i][k])
                    dp[i][k] = nowaIlość;
            }
        }
    }

    return dp[b.size()][kwota];
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> b(n);
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    std::vector<int> c(n);
    for (int i = 0; i < n; i++)
        std::cin >> c[i];

    int k;
    std::cin >> k;

    std::cout << banknoty(k, b, c);
}