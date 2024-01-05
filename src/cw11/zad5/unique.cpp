#include <iostream>
#include <vector>

int unique(const std::vector<int>& b, int k) {
    int** dp = new int*[k];
    
    for (int i = 0; i < k; i++)
        dp[i] = new int[b.size()];
    
    int* dp_prim = new int[k];
    dp_prim[0] = 0;

    for (int m = 0; m < b.size(); m++)
        dp[0][m] = 1;
    
    for (int j = 1; j <= k; j++) {
        dp_prim[j] = 0;
        for (int m = 0; m < b.size(); m++) {
            dp[j][m] = 0;
            if (k - b[m] >= 0) {
                for (int i = 0; i <= m; i++)
                    dp[j][m] += dp[k - b[m]][i];
            }
            dp_prim[j] += dp[j][m];
        }
    }

    return dp_prim[k];
}

int main() {
    std::cout << unique({7, 8, 9, 10, 20, 50, 100}, 18) << "\n";
    std::cout << unique({7, 8, 9, 10, 20, 50, 100}, 19) << "\n";
}