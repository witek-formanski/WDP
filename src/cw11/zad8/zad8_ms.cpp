#include <iostream>
#include <vector>

using namespace std;

template <typename T>
T **make_2d(int x, int y, T defaultVal);

template <typename T>
void free_2d(T **dp, int y);

template <typename T>
void print(T **dp, int x, int y, void (*printT)(T));

int find_level(int l, int r, int **dp)
{
    int maxLvl = 0;
    for (int i = l; i < r; i++)
    {
        int leftLvl = dp[l][i], rightLvl = dp[i + 1][r];
        if (abs(leftLvl - rightLvl) == 1)
        {
            int currLvl = max(leftLvl, rightLvl) + 1;
            if (maxLvl < currLvl)
            {
                maxLvl = currLvl;
            }
        }
    }
    return maxLvl;
}

void print_number(int n)
{
    cout << n << " ";
}

int find_max(int n, int **dp)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] > max)
                max = dp[i][j];
        }
    }
    return max;
}

// T(n) = O(n^3)
// M(n) = O(n^2)
int segment(const vector<int> &t)
{
    int n = (int)t.size();
    int **dp = make_2d(n, n, 0);

    // every interval <i,i> has a level of t[i]
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = t[i];
    }

    // calculate level for every interval <l,r>, l<=r
    for (int d = 1; d < n; d++)
    {
        for (int l = 0; l + d < n; l++)
        {
            int r = l + d;
            dp[l][r] = find_level(l, r, dp);
        }
    }

    int results = find_max(n, dp);
    free_2d(dp, n);
    return results;
}

int main()
{
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }

    int results = segment(t);
    cout << results << endl;
    t.clear();
    return 0;
}

template <typename T>
T **make_2d(int x, int y, T defaultVal)
{
    T **ret = (T **)malloc((size_t)y * (sizeof(T *)));
    for (int i = 0; i < y; i++)
    {
        ret[i] = (T *)malloc((size_t)x * sizeof(T));
        for (int j = 0; j < x; j++)
        {
            ret[i][j] = defaultVal;
        }
    }
    return ret;
}

template <typename T>
void free_2d(T **dp, int y)
{
    for (int i = 0; i < y; i++)
    {
        free(dp[i]);
    }
    free(dp);
}

template <typename T>
void print(T **dp, int x, int y, void (*printT)(T))
{
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            printT(dp[i][j]);
        }
        cout << endl;
    }
}