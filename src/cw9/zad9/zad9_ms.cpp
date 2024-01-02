// original: @asajab
// i've studied his code to understand the idea

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct p
{
    int x, y, level;
};
typedef struct p *Point;

Point create_point(int x, int y, int level)
{
    Point newPoint = (Point)malloc(sizeof(p));
    newPoint->x = x;
    newPoint->y = y;
    newPoint->level = level;
    return newPoint;
}

vector<vector<bool>> load_map(int x, int y)
{
    vector<vector<bool>> ocean;
    for (int ys = 0; ys < y; ys++)
    {
        vector<bool> currentRow;
        for (int xs = 0; xs < x; xs++)
        {
            int i;
            cin >> i;
            currentRow.push_back((bool)i);
        }
        ocean.push_back(currentRow);
    }

    return ocean;
}

// push to deque new point, should levelup?
void enqueue(deque<Point> &toBeVisited, int x, int y, int l, bool levelUp)
{
    if (levelUp)
    {
        toBeVisited.push_back(create_point(x, y, l + 1));
    }
    else
    {
        toBeVisited.push_front(create_point(x, y, l));
    }
}

bool are_proper_coordinates(int xs, int ys, int x, int y)
{
    return xs >= 0 && xs < x && ys >= 0 && ys < y;
}

const int dx[] = {0, 0, 1, -1};
const int dy[] = {-1, 1, 0, 0};

int wyspa(const vector<vector<bool>> &mapa)
{
    int y = (int)mapa.size();
    if (y <= 0)
        return 0;
    int x = (int)mapa[0].size();

    int maxIsland = -1;

    deque<Point> toBeVisited;
    vector<vector<bool>> wasVisited(y, vector<bool>(x, false));

    for (int i = 0; i < x; i++)
    {
        // push top line
        wasVisited[0][i] = true;
        enqueue(toBeVisited, i, 0, 0, mapa[0][i]);
        // push bottom line
        wasVisited[y - 1][i] = true;
        enqueue(toBeVisited, i, y - 1, 0, mapa[y - 1][i]);
    }

    for (int i = 0; i < y; i++)
    {
        // push left line
        wasVisited[i][0] = true;
        enqueue(toBeVisited, 0, i, 0, mapa[i][0]);
        // push right line
        wasVisited[i][x - 1] = true;
        enqueue(toBeVisited, x - 1, i, 0, mapa[i][x - 1]);
    }

    while (!toBeVisited.empty())
    {
        Point current = toBeVisited.front();
        toBeVisited.pop_front();

        if (mapa[current->y][current->x] && current->level > maxIsland)
        {
            maxIsland = current->level;
        }
        for (int i = 0; i < 4; ++i)
        {
            int ys = current->y + dy[i], xs = current->x + dx[i];
            if (!are_proper_coordinates(xs, ys, x, y) || wasVisited[ys][xs])
                continue;
            wasVisited[ys][xs] = true;

            // land -> water should not levelup
            bool levelUp = mapa[ys][xs] != mapa[current->y][current->x];
            if (levelUp && !mapa[ys][xs])
                current->level--;

            enqueue(toBeVisited, xs, ys, current->level, levelUp);
        }
        free(current);
    }

    // cleanup
    for(vector<bool> row : wasVisited){
        row.clear();
    }
    wasVisited.clear();

    return maxIsland;
}

int main()
{
    int x, y;
    cin >> y >> x;
    vector<vector<bool>> ocean = load_map(x, y);

    int maxLevel = wyspa(ocean);
    cout << maxLevel << endl;
    ocean.clear();
}