#define IMPOSSIBLE -1

#include <iostream>

using namespace std;

int **make_2d(int x, int y);
void free_2d(int **dp, int y);
void print(int **dp, int x, int y);

// O((sum / denominations[maxDenominationId]) + 1)
int get_combination_of_denominations_count(int sum, int maxDenominationId, int *denominations, int **dp)
{
    // we substract id by one, because dp[sum][0] represents none of denominatins
    int value = denominations[maxDenominationId - 1];

    int possibilitiesCount = 0;
    int i = 0;
    while (true)
    {
        int newSum = sum - (value * (i++));
        int fillingPosibilities = IMPOSSIBLE;
        if (newSum < 0)
            break;
        if (newSum >= 0)
        {
            fillingPosibilities = dp[newSum][maxDenominationId - 1];
        }
        if (fillingPosibilities == IMPOSSIBLE)
            continue;

        possibilitiesCount += fillingPosibilities;
    };
    if (possibilitiesCount == 0)
        return IMPOSSIBLE;
    return possibilitiesCount;
}

// T(n) = O(n)
bool can_be_represented_only_in_one_way(int *row, int n)
{
    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        if (row[i] != IMPOSSIBLE)
        {
            c++;
            if (row[i] != 1)
            {
                return false;
            }
        }
    }
    if (c > 0)
        return true;
    return false;
}

// T(n) = O(k * n * max{(k / denominals[i-1]) + 1} | 0<i<=n)
// M(n) = O(k*n)
int find_possibilities_denom(int k, int n, int *denominals)
{
    int **dp = make_2d(n + 1, k + 1);
    // 0 we can give out in exacly one way: empty multiset
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = 1;
    }
    // we cannot give out sum greater than 0 without any denominals
    for (int i = 1; i <= k; i++)
    {
        dp[i][0] = IMPOSSIBLE;
    }

    int maxSum = 0;

    // calculate possibilities for sum 0...k for every nominal
    for (int sum = 1; sum <= k; sum++)
    {
        for (int i = 1; i <= n; i++)
        {
            dp[sum][i] = get_combination_of_denominations_count(sum, i, denominals, dp);
        }

        // does fit out search
        bool isOneWay = can_be_represented_only_in_one_way(dp[sum], n);
        if (isOneWay && sum > maxSum)
        {
            maxSum = sum;
        }
    }

    print(dp, n + 1, k + 1);
    free_2d(dp, k + 1);
    return maxSum;
}

int main()
{
    int n;
    cin >> n;

    int *denominals = (int *)malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        cin >> denominals[i];
    }

    int k;
    cin >> k;

    int results = find_possibilities_denom(k, n, denominals);
    cout << results << endl;

    free(denominals);
    return 0;
}

int **make_2d(int x, int y)
{
    int **ret = (int **)malloc((size_t)y * (sizeof(int *)));
    for (int i = 0; i < y; i++)
    {
        ret[i] = (int *)malloc((size_t)x * sizeof(int));
        for (int j = 0; j < x; j++)
        {
            ret[i][j] = 0;
        }
    }
    return ret;
}

void free_2d(int **dp, int y)
{
    for (int i = 0; i < y; i++)
    {
        free(dp[i]);
    }
    free(dp);
}

void print(int **dp, int x, int y)
{
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}