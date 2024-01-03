#include <iostream>
#include <vector>

using namespace std;

template <typename T>
T **make_2d(int x, int y, T defaultVal);

template <typename T>
void free_2d(T **dp, int y);

template <typename T>
void print(T **dp, int x, int y, void (*printT)(T));

void printPair(pair<bool, int> p);


pair<bool, int> is_possible(int e, int maxLayerId, const vector<int> &t, pair<bool, int> **dp)
{
    int layerEnergy = t[maxLayerId - 1];

    for (int i = 0; i <= 1; i++)
    {
        int currentEnergy = e - (i * layerEnergy);
        if (currentEnergy < 0)
            continue;
        pair<bool, int> isPossibleCurrentEnergy = dp[currentEnergy][maxLayerId - 1];
        if (isPossibleCurrentEnergy.first)
        {
            return make_pair(true, isPossibleCurrentEnergy.second + i);
        }
    }
    return make_pair(false, 0);
}

// O(t.size())
vector<int> find_representation(int k, int e, const vector<int> &t, pair<bool, int> **dp)
{
    int n = (int)t.size();
    int i = k - 1;

    int currentSum = e;
    int currId = n;

    vector<int> layers(k);
    while (i >= 0)
    {
        int currVal = t[currId - 1];
        int newSum = currentSum - currVal;
        if (newSum >= 0 && dp[newSum][currId - 1].first && dp[newSum][currId - 1].second == i)
        {
            layers[i--] = currId -1;
            currentSum = newSum;
        }
        currId--;
    }
    return layers;
}

// O(e*n)
// I am afraid that some data exists which will lead program to wrong output
// something like when there are multiple possibilities to represent sum and it will fail in is_possible
// but i might be wrong
vector<int> energia(int k, const vector<int> &t, int e)
{
    int n = (int)t.size();
    pair<bool, int> **dp = make_2d<pair<bool, int>>(n + 1, e + 1, make_pair(false, 0));

    // energy 0 we do not need anything
    dp[0][0] = make_pair(true, 0);

    // O(e * n)
    for (int energy = 1; energy <= e; energy++)
    {
        for (int i = 1; i <= n; i++)
        {
            dp[energy][i] = is_possible(energy, i, t, dp);
        }
    }

    //print(dp, n + 1, e + 1, printPair);

    bool isPossible = dp[e][n].first && dp[e][n].second == k;
    if (!isPossible)
    {
        free_2d(dp, e + 1);
        vector<int> empty;
        return empty;
    }
    // O(n)
    vector<int> layerList = find_representation(k, e, t, dp);
    free_2d(dp, e + 1);
    return layerList;
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

    int k;
    cin >> k;

    int e;
    cin >> e;

    vector<int> results = energia(k, t, e);
    if (results.empty())
    {
        cout << "impossible" << endl;
    }
    else
    {
        for (int c : results)
        {
            cout << c << endl;
        }
    }

    results.clear();
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

void printPair(pair<bool, int> p)
{
    cout << "(" << p.first << ", " << p.second << ") ";
}