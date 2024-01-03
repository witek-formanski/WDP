#define IMPOSSIBLE -1

#include <iostream>

using namespace std;

int **make_2d(int x, int y);
void free_2d(int **dp, int y);
void print(int **dp, int x, int y);

int get_min_denominations_count(int sum, int maxDenominationId, int *denominations, int **dp)
{
    int minOfDenominals = INT32_MAX - 1;
    bool isPossible = false;
    // we substract id by one, because dp[sum][0] represents none of denominations
    int value = denominations[maxDenominationId - 1];

    int i = 0;
    while (true)
    {
        int currI = i;
        int newSum = sum - (value * (i++));
        
        int minFiling = IMPOSSIBLE;
        if (newSum < 0)
            break;
        if (newSum >= 0)
        {
            minFiling = dp[newSum][maxDenominationId - 1];
        }
        if (minFiling == IMPOSSIBLE)
            continue;
        
        minFiling += currI;
        if (minFiling < minOfDenominals)
        {
            minOfDenominals = minFiling;
            isPossible = true;
        }
    }
    if (isPossible)
        return minOfDenominals;
    return IMPOSSIBLE;
}

int find_min_denom(int k, int n, int *denominals)
{
    int **dp = make_2d(n + 1, k + 1);
    for (int i = 1; i <= k; i++)
    {
        dp[i][0] = IMPOSSIBLE;
    }

    for (int sum = 1; sum <= k; sum++)
    {
        for (int i = 1; i <= n; i++)
        {
            dp[sum][i] = get_min_denominations_count(sum, i, denominals, dp);
        }
    }

    int results = dp[k][n];
    free_2d(dp, k + 1);
    return results;
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

    int results = find_min_denom(k, n, denominals);
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