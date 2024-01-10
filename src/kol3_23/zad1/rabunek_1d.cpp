#include <vector>

int* init_dp(int k) {
    int* dp = new int[k + 1];
    std::fill(dp, dp + k + 1, -1);
    return dp;
}

int rabunek(std::vector<int> n, int k) {
    int* dp = init_dp(k);

}