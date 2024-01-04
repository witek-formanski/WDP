#include <iostream>

using namespace std;

template <typename T>
T **make_2d(int x, int y, T defaultVal);
template <typename T>
void free_2d(T **dp, int y);
template <typename T>
void print(T **dp, int x, int y, void (*printT)(T));
void print_number(int n);

int find_max_passengers_on_junction(int y, int x, int **dp)
{
    int junctionToTheRight = dp[y][x + 1];
    int juntionBelow = dp[y + 1][x];
    return max(junctionToTheRight, juntionBelow);
}

// T(n) = O(n^2)
// M(n) = O(n^2)
int autobus(int **passengers, int n, int m)
{
    int **dp = make_2d<int>(n, m, 0);
    const int northStreet = n - 1;
    const int eastStreet = m - 1;

    dp[eastStreet][northStreet] = passengers[eastStreet][northStreet];

    // fill north edge
    for (int i = eastStreet - 1; i >= 0; i--)
    {
        dp[i][northStreet] = dp[i + 1][northStreet] + passengers[i][northStreet];
    }

    // fill east edge
    for (int i = northStreet - 1; i >= 0; i--)
    {
        dp[eastStreet][i] = dp[eastStreet][i + 1] + passengers[eastStreet][i];
    }

    // fill rest of junctions \/
    // distance between the street on north / east edge
    for (int d = 1; d <= n - 1; d++)
    {
        // iterator from nort/east corner od distance d to the furtherest on given street
        for (int i = n - 1 - d; i >= 0; i--)
        {
            // north street walker
            if (northStreet - d >= 0)
                dp[i][northStreet - d] = passengers[i][northStreet - d] + find_max_passengers_on_junction(i, northStreet - d, dp);

            // east street walker
            if (eastStreet - d >= 0)
                dp[eastStreet - d][i] = passengers[eastStreet - d][i] + find_max_passengers_on_junction(eastStreet - d, i, dp);
        }
    }

    // cout<<endl;
    // print(dp,n,m, print_number);
    int results = dp[0][0];
    free_2d(dp, n);
    return results;
}

int main()
{
    int n,m;
    cin >> n>>m;

    int **passengers = make_2d<int>(n, m, 0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> passengers[i][j];
        }
    }

    int results = autobus(passengers, n,m);
    cout << results << endl;
    free_2d(passengers, m);
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

void print_number(int n)
{
    cout << n << " ";
}