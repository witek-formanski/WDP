// https://leetcode.com/problems/swim-in-rising-water/solutions/4119399/finding-the-maximum-in-minimum-using-binary-search-on-answers-100-time/

#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

vector<int> get_sorted_all_values(const vector<vector<int>> &x)
{
    set<int> values;
    for (vector<int> row : x)
    {
        for (int c : row)
        {
            values.insert(c);
        }
    }

    vector<int> results;
    for (int c : values)
    {
        results.push_back(c);
    }
    values.clear();
    return results;
}

const int DIRECTIONS_COUNT = 4;
const int Dx[] = {-1, 0, 1, 0};
const int Dy[] = {0, 1, 0, -1};

bool are_proper_cords(int x, int y, int n, int m)
{
    return x >= 0 && y >= 0 && x < n && y < m;
}

bool can_traverse(const vector<vector<int>> &amp, int maxHeight)
{
    int m = (int)amp.size();
    int n = (int)amp[0].size();
    vector<vector<bool>> wasVisited(m, vector<bool>(n, false));
    queue<pair<int, int>> toBeVisited;
    if (amp[0][0] > maxHeight)
        return false;
    toBeVisited.push(make_pair(0, 0));
    wasVisited[0][0] = true;

    bool isPossible = false;

    while (!toBeVisited.empty())
    {
        pair<int, int> current = toBeVisited.front();
        toBeVisited.pop();

        int x = current.first, y = current.second;
        if (x == n - 1 && y == m - 1)
        {
            isPossible = true;
            break;
        }

        for (int i = 0; i < DIRECTIONS_COUNT; i++)
        {
            int nX = x + Dx[i], nY = y + Dy[i];
            if (!are_proper_cords(nX, nY, n, m) || wasVisited[nY][nX] || amp[nY][nX] > maxHeight)
                continue;
            toBeVisited.push(make_pair(nX, nY));
            wasVisited[nY][nX] = true;
        }
    }

    while (!toBeVisited.empty())
    {
        toBeVisited.pop();
    }
    for (vector<bool> row : wasVisited)
    {
        row.clear();
    }
    wasVisited.clear();
    return isPossible;
}

// binsearch po wyniku
// T(n) = O((n^2)*(log(n^2) + logM)), M - największa wartość w amp
int wysokosc(const vector<vector<int>> &amp)
{
    if (amp.size() == 0 || amp[0].size() == 0)
        return false;
    vector<int> heights = get_sorted_all_values(amp);
    int l = 0, p = (int)heights.size() - 1;
    while (l < p)
    {
        int pivot = (l + p) / 2;
        bool isPossible = can_traverse(amp, heights[pivot]);
        if (isPossible)
        {
            p = pivot;
        }
        else
        {
            l = pivot +1;
        }
    }

    int results = heights[l];
    heights.clear();
    return results;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> amp(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> amp[i][j];
        }
    }

    int results = wysokosc(amp);
    cout << results << endl;

    for (vector<int> row : amp)
    {
        row.clear();
    }
    amp.clear();
    return 0;
}