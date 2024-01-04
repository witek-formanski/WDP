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

bool can_traverse(const vector<vector<int>> &amp, int time, int xStart, int yStart)
{
    int m = (int)amp.size();
    int n = (int)amp[0].size();
    vector<vector<bool>> wasVisited(m, vector<bool>(n, false));
    queue<pair<int, int>> toBeVisited;
    if (amp[yStart][xStart] <= time)
        return false;
    toBeVisited.push(make_pair(xStart, yStart));
    wasVisited[yStart][xStart] = true;

    bool isPossible = false;

    while (!toBeVisited.empty())
    {
        pair<int, int> current = toBeVisited.front();
        toBeVisited.pop();

        int x = current.first, y = current.second;
        if (x == n - 1 || y == m - 1 || x == 0 || y == 0)
        {
            isPossible = true;
            break;
        }

        for (int i = 0; i < DIRECTIONS_COUNT; i++)
        {
            int nX = x + Dx[i], nY = y + Dy[i];
            if (!are_proper_cords(nX, nY, n, m) || wasVisited[nY][nX] || amp[nY][nX] <= time)
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
// T(n) = O((n^2)*(log(n^2) + logM)), M - największa wartość w mapa
int sadzawka(const vector<vector<int>> &mapa, int jas_x, int jas_y)
{
    if (mapa.size() == 0 || mapa[0].size() == 0)
        return false;
    vector<int> timeline = get_sorted_all_values(mapa);
    int l = 0, p = (int)timeline.size() - 1;
    while (l < p)
    {
        int currTime = (l + p) / 2;
        bool isPossible = can_traverse(mapa, timeline[currTime], jas_x, jas_y);
        if (isPossible)
        {
            l = currTime + 1;
        }
        else
        {
            p = currTime;
        }
    }

    int results = timeline[l];
    timeline.clear();
    return results;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    int x, y;
    cin >> x >> y;

    int results = sadzawka(map, x, y);
    cout << results << endl;

    for (vector<int> row : map)
    {
        row.clear();
    }
    map.clear();
    return 0;
}