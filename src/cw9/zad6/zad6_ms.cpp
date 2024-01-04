#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum directions
{
    north = 0,
    east = 1,
    south = 2,
    west = 3
};

typedef struct j *junction;
struct j
{
    int x, y;
    directions direction;
};

junction make_junction(int x, int y, directions direction)
{
    junction newJunction = (junction)malloc(sizeof(j));
    newJunction->x = x;
    newJunction->y = y;
    newJunction->direction = direction;
    return newJunction;
}

directions turn_right(directions dir)
{
    int d = ((int)dir + 1) % 4;
    return (directions)d;
}

const int Dx[] = {0, 1, 0, -1};
const int Dy[] = {-1, 0, 1, 0};

bool are_proper_cords(int x, int y, int m, int n)
{
    return x >= 0 && y >= 0 && x < m && y < n;
}

void calc_cords(int x, int y, directions direction, int *rX, int *rY)
{
    int d = (int)direction;
    *rX = x + Dx[d], *rY = y + Dy[d];
}

bool can_go(int x, int y, int nX, int nY, int m, int n, directions direction, const vector<vector<bool>> visitHistory, const vector<vector<vector<bool>>> ulice)
{
    if (!are_proper_cords(nX, nY, m, n))
        return false;
    if (visitHistory[nY][nX])
    {
        // he was here, but he can go again, just not the same way
        bool visitedAllPosibilities = true;
        int cX, cY;
        calc_cords(nX, nY, direction, &cX, &cY);
        if (are_proper_cords(cX, cY, m, n))
            visitedAllPosibilities = visitedAllPosibilities && visitHistory[cY][cX];
        calc_cords(nX, nY, turn_right(direction), &cX, &cY);
        if (are_proper_cords(cX, cY, m, n))
            visitedAllPosibilities = visitedAllPosibilities && visitHistory[cY][cX];

        return !visitedAllPosibilities;
    }
    return ulice[y][x][(int)direction];
}

void plan_visit(int x, int y, directions direction, queue<junction> &toBeVisited, vector<vector<bool>> &visitHistory)
{
    junction toVisit = make_junction(x, y, direction);
    toBeVisited.push(toVisit);
    visitHistory[y][x] = true;
}

// T(n) = O(m*n)
// M(n) = O(m*n)
bool can_reach_destination(const vector<vector<vector<bool>>> ulice)
{
    int n = (int)ulice.size();
    if (n <= 0)
        return false;
    int m = (int)ulice[0].size();

    bool canReach = false;

    vector<vector<bool>> visitHistory(n, vector<bool>(n, false));
    queue<junction> toBeVisited;

    visitHistory[0][0] = true;
    junction corner = make_junction(0, 0, east);
    toBeVisited.push(corner);
    while (!toBeVisited.empty())
    {
        junction current = toBeVisited.front();
        toBeVisited.pop();

        if (current->x == m - 1 && current->y == n - 1)
        {
            // hurray, we are in the right bottom corner
            canReach = true;
            break;
        }

        directions direction = current->direction;
        for (int i = 0; i < 2; i++)
        {
            int nX, nY;
            calc_cords(current->x, current->y, direction, &nX, &nY);
            if (can_go(current->x, current->y, nX, nY, m, n, direction, visitHistory, ulice))
            {
                plan_visit(nX, nY, direction, toBeVisited, visitHistory);
            }
            direction = turn_right(direction);
        }

        free(current);
    }

    for (vector<bool> row : visitHistory)
    {
        row.clear();
    }
    visitHistory.clear();

    return canReach;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<vector<bool>>> ulice(n, vector<vector<bool>>(m, vector<bool>(4, false)));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int d = 0; d < 4; d++)
            {
                int can;
                cin >> can;
                if (can)
                {
                    ulice[i][j][d] = true;
                }
            }
        }
    }

    bool canReach = can_reach_destination(ulice);
    cout << canReach << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ulice[i][j].clear();
        }
        ulice[i].clear();
    }
    ulice.clear();

    return 0;
}