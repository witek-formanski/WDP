#include <algorithm>
#include <cmath>
#include <iostream>

int** get_sum(int mice[], int n) {
    int** sum = new int*[n];
    for (int i = 0; i < n; i++) {
        sum[i] = new int[n]{0};
        sum[i][i] = mice[i];
    }

    int* prefix_sum = new int[n]{mice[0]};
    for (int i = 1; i < n; i++)
        prefix_sum[i] = prefix_sum[i - 1] + mice[i];

    int* length_coefficient = new int[n];
    for (int i = 0; i < n; i++)
        length_coefficient[0] = pow(i + 1, 2);

    for (int length = 2; length <= n; length++) {
        for (int i = 0; i < n - length + 2; i++) {
            sum[i][i + length - 1] = std::max(
                sum[i][i + length - 2] + mice[i + length - 1] + (int)pow(length - 2, 2) - (int)pow(length - 1, 2),
                0);
        }
    }

    return sum;
}

int** get_max_in_interval(int** sum, int n) {
    int** interval_max = new int*[n];
    for (int i = 0; i < n; i++) {
        interval_max[i] = new int[n]{0};
        interval_max[i][i] = sum[i][i];
    }

    int j;
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            j = i + length - 1;
            interval_max[i][j] = std::max(
                sum[i][j],
                std::max(
                    interval_max[i + 1][j],
                    interval_max[i][j - 1]));
        }
    }

    return interval_max;
}

void delete_array(int** tab, int n, int m) {
}

void print(int** tab, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            std::cout << tab[i][j] << "\t";
        std::cout << "\n";
    }
}

int mice_in_the_corridor(int mice[], int n, int k) {
    if (k < 1 || k > n)
        return -1;

    int** dp = new int*[k - 1];
    for (int i = 0; i < k - 1; i++) {
        dp[i] = new int[n - 1]{0};
    }

    int** interval_max = get_max_in_interval(get_sum(mice, n), n);

    for (int i = 0; i < n - 1; i++) {
        dp[0][i] = interval_max[0][i];
        // dp[0][i] = interval_max[i + 1][n - 1];
    }

    for (int cat = 2; cat < k; cat++)
        dp[cat - 1][cat - 1] = dp[cat - 2][cat - 2] + mice[cat - 1];

    std::cout << "\n";

    for (int cat = 2; cat < k; cat++) {
        for (int i = cat - 1; i < n - 1; i++) {
            // dp[cat - 1][i] = dp[cat - 2][i];
            // dp[cat - 1][i] = interval_max[i + 1][n - 1];
        }
        // print(dp[cat - 1], 2, n);
        std::cout << "\n";
    }
    // print(dp, k - 1, n);

    return 1;
}

int main() {
    // print()
    int n = 8;
    int* mice = new int[8]{1, 5, 1, 4, 3, 2, 7, 0};
    int** sum = get_sum(mice, n);
    // print(sum, n, n);
    std::cout << "\n";
    int** interval_max = get_max_in_interval(sum, n);
    // print(interval_max, n, n);
    std::cout << "\n";
    int res = mice_in_the_corridor(mice, n, 8);
}