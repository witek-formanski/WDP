#include <vector>

bool** init_dp(int n_size, int k) {
    bool** dp = new bool*[k+1];
    for (int i = 0; i <= k; i++)
        dp[i] = new bool[n_size+1]{false};

    dp[0][n_size] = true;
    return dp;
}

void delete_dp(bool** dp, int k) {
    for (int i = 0; i <= k; i++)
        delete[] dp[i];
    delete[] dp;
}

int rabunek(std::vector<int> n, int k) {
}