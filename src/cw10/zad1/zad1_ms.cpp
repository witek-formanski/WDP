#define DIRECTIONS_COUNT 8
#define INITIAL_DIRECTION -1

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef struct c *Jump;
struct c
{
    pair<int, int> cords;
    int direction;
};

Jump new_jump(pair<int, int> cords, int direction)
{
    Jump newJump = (Jump)malloc(sizeof(c));
    newJump->cords = cords;
    newJump->direction = direction;
    return newJump;
}

Jump new_jump(int x, int y, int direction)
{
    return new_jump(make_pair(x, y), direction);
}

void make_jump(stack<Jump> &visitStack, vector<vector<bool>> &wasVisited, Jump jump)
{
    visitStack.push(jump);
    wasVisited[jump->cords.second][jump->cords.first] = true;
}

bool undo_jump(stack<Jump> &visitStack, vector<vector<bool>> &wasVisited)
{
    if (visitStack.empty())
        return false;
    Jump jump = visitStack.top();
    visitStack.pop();
    wasVisited[jump->cords.second][jump->cords.first] = false;
    free(jump);

    return !visitStack.empty();
}

bool is_ok(int x, int y, int n)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}

int next_direction(int direction){
    return direction+1;
}

const int Dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int Dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

vector<pair<int, int>> jump(int n)
{
    int fieldsCount = n * n;
    vector<vector<bool>> wasVisited(n, vector<bool>(n, false));
    stack<Jump> visitStack;

    make_jump(visitStack, wasVisited, new_jump(0, 0, INITIAL_DIRECTION));
    while ((int)visitStack.size() < fieldsCount)
    {
        Jump current = visitStack.top();
        int x = -1, y = -1;
        do
        {
            current->direction = next_direction(current->direction);
            if (current->direction >= DIRECTIONS_COUNT)
            {
                break;
            }

            // calculate next jump's cords
            x = current->cords.first + Dx[current->direction];
            y = current->cords.second + Dy[current->direction];
        } while (!is_ok(x, y, n) || wasVisited[y][x]);

        if (current->direction >= DIRECTIONS_COUNT)
        {
            // all possibilities were used, we must rechoose something before
            if (!undo_jump(visitStack, wasVisited))
            {
                break;
            }
            continue;
        }

        Jump nextJump = new_jump(x, y, INITIAL_DIRECTION);
        make_jump(visitStack, wasVisited, nextJump);
    }

    // clear visited
    for (vector<bool> row : wasVisited)
    {
        row.clear();
    }
    wasVisited.clear();

    if ((int)visitStack.size() < fieldsCount)
    {
        // is not possible
        while (!visitStack.empty())
        {
            free(visitStack.top());
            visitStack.pop();
        }
        vector<pair<int, int>> empty;
        return empty;
    }

    // copy found path
    vector<pair<int, int>> visitHistory(fieldsCount);
    for (int i = fieldsCount - 1; i >= 0; i--)
    {
        Jump jump = visitStack.top();
        visitStack.pop();
        visitHistory[i] = make_pair(jump->cords.first, jump->cords.second);
        free(jump);
    }
    return visitHistory;
}

bool validate(const vector<pair<int, int>> path, int n)
{
    if (path.size() != n * n)
    {
        return false;
    }

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[path[0].second][path[0].first] = true;

    for (int i = 1; i < n * n; i++)
    {
        int x = abs(path[i - 1].first - path[i].first);
        int y = abs(path[i - 1].second - path[i].second);
        if ((x != 1 || y != 2) && (x != 2 || y != 1))
        {
            return false;
        }
        if (!is_ok(path[i].first, path[i].second, n))
        {
            return false;
        }
        if (visited[path[i].second][path[i].first])
            return false;
        visited[path[i].second][path[i].first] = true;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> path = jump(n);
    if (path.empty())
    {
        cout << "impossible" << endl;
        return 0;
    }

    if (!validate(path, n))
    {
        cout << "wrong results :(" << endl;
        path.clear();
        return 1;
    }
    for (pair<int, int> jump : path)
    {
        cout << jump.first << " " << jump.second << endl;
    }
    path.clear();
    return 0;
}