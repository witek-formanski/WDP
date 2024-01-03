#define IMPOSSIBLE -1

#include <iostream>
#include <cstdlib>

using namespace std;

int **make_2d(int x, int y);
void free_2d(int **dp, int y);
void print(int **dp, int x, int y);

int ileBanknotow(int k, int maxNominal, int *b, int *c, int **dp)
{
    int min = INT32_MAX - 1;
    bool wasAltered = false;
    for (int i = 0; i <= c[maxNominal]; i++)
    {
        int newSum = k;
        newSum -= i * b[maxNominal];
        int currentCount = 0;
        if (newSum < 0)
        {
            currentCount = dp[k][maxNominal + 1 - 1];
        }
        else
        {
            int minForNewSum = dp[newSum][maxNominal + 1 - 1];
            if (minForNewSum == IMPOSSIBLE)
                currentCount = IMPOSSIBLE;
            else
                currentCount = i + minForNewSum;
        }
        if (currentCount != IMPOSSIBLE && currentCount < min)
        {
            min = currentCount;
            wasAltered = true;
        }
    }
    if (wasAltered)
        return min;
    return IMPOSSIBLE;
}

int banknoty(int k, int n, int *b, int *c)
{

    int **dp = make_2d(n + 1, k + 1);
    for (int i = 1; i <= k; i++)
    {
        dp[i][0] = IMPOSSIBLE;
    }

    for (int sum = 1; sum <= k; sum++)
    {
        for (int i = 0; i < n; i++)
        {
            dp[sum][i + 1] = ileBanknotow(sum, i, b, c, dp);
        }
    }

    int ans = dp[k][n];
    free_2d(dp, k + 1);
    return ans;
}

int main()
{
    int n;
    cin >> n;

    int *b = (int *)malloc((size_t)n * sizeof(int));
    int *c = (int *)malloc((size_t)n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    int k;
    cin >> k;

    int ans = banknoty(k, n, b, c);
    cout << ans;

    free(b);
    free(c);
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