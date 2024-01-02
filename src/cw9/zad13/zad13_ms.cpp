#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef struct p *Point;
struct p
{
    int x, y;
};

typedef struct s *Square;
struct s
{
    int height;
    bool isCity;
    Point cords;

public:
    bool operator()(Square &a, Square &b)
    {
        // we want smallest item to be first
        return a->height > b->height;
    }
};

Point new_point(int x, int y)
{
    Point newPoint = (Point)malloc(sizeof(p));
    newPoint->x = x;
    newPoint->y = y;
    return newPoint;
}

Square new_square(int height, bool isCity, int x, int y)
{
    Square newSquare = (Square)malloc(sizeof(s));
    newSquare->height = height;
    newSquare->cords = new_point(x, y);
    newSquare->isCity = isCity;
    return newSquare;
}

Square get_square(const vector<vector<Square>> map, Point p)
{
    return map[p->y][p->x];
}

bool are_proper_coordinates(int xs, int ys, int x, int y)
{
    return xs >= 0 && xs < x && ys >= 0 && ys < y;
}

bool are_proper_coordinates(Point p, int x, int y)
{
    return are_proper_coordinates(p->x, p->y, x, y);
}

const int dx[] = {0, 0, 1, -1};
const int dy[] = {-1, 1, 0, 0};

bool was_visited(const set<pair<int, int>> history, Point p)
{
    return history.find(make_pair(p->x, p->y)) != history.end();
}

bool was_visited(const vector<vector<bool>> history, Point p)
{
    return history[p->y][p->x];
}

bool was_visited(const vector<vector<bool>> history, Square sq)
{
    return was_visited(history, sq->cords);
}

void try_push(queue<Square> &q, vector<vector<bool>> &history, Square sq)
{
    if (was_visited(history, sq))
        return;
    q.push(sq);
    history[sq->cords->y][sq->cords->x] = true;
}

// T(n) = O(n * xy * log (xy)), gdzie xy to rozmiar mapy, a n liczba kwadratów należących do miasta
int powodz(const vector<vector<pair<int, bool>>> mapa)
{
    int y = (int)mapa.size();
    if (y <= 0)
        return 0;
    int x = (int)mapa[0].size();

    vector<vector<bool>> wasVisited(y, vector<bool>(x, false));
    vector<vector<Square>> map;
    priority_queue<Square> citySquares;

    for (int ys = 0; ys < y; ys++)
    {
        vector<Square> row;
        for (int xs = 0; xs < x; xs++)
        {
            Square newSquare = new_square(mapa[ys][xs].first, mapa[ys][xs].second, xs, ys);
            row.push_back(newSquare);
            if (newSquare->isCity)
            {
                citySquares.push(newSquare);
            }
        }
        map.push_back(row);
    }

    int engineCount = 0;

    while (!citySquares.empty())
    {

        Square currentLowest = citySquares.top();
        citySquares.pop();
        if (was_visited(wasVisited, currentLowest))
            continue;
        engineCount++;

        queue<pair<Square, int>> toBeVisited;
        toBeVisited.push(make_pair(currentLowest, currentLowest->height));
        wasVisited[currentLowest->cords->y][currentLowest->cords->x] = true;

        set<pair<int, int>> wasLocalVisited;
        while (!toBeVisited.empty())
        {
            auto curr = toBeVisited.front();
            toBeVisited.pop();

            Square current = curr.first;
            int minHeight = curr.second;

            // try go all 4 ways
            for (int i = 0; i < 4; i++)
            {
                // make possible next move
                Point possibleNext = new_point(current->cords->x + dx[i], current->cords->y + dy[i]);
                if (!are_proper_coordinates(possibleNext, x, y))
                {
                    free(possibleNext);
                    continue;
                }
                if (was_visited(wasLocalVisited, possibleNext) || was_visited(wasVisited, possibleNext))
                {
                    free(possibleNext);
                    continue;
                }
                Square currentHipot = get_square(map, possibleNext);
                free(possibleNext);

                if (currentHipot->isCity && currentHipot->height < minHeight)
                    continue;

                int newHeight = max(minHeight, currentHipot->height);
                toBeVisited.push(make_pair(currentHipot, newHeight));
                if (currentHipot->isCity)
                    wasVisited[currentHipot->cords->y][currentHipot->cords->x] = true;
                wasLocalVisited.insert(make_pair(currentHipot->cords->x, currentHipot->cords->y));
            }
        }
        wasLocalVisited.clear();
    }


    // clean memory
    for(vector<bool> row : wasVisited){
        row.clear();
    }
    wasVisited.clear();
    for(vector<Square> row : map){
        for(Square sq : row){
            free(sq->cords);
            free(sq);
        }
        row.clear();
    }
    map.clear();

    return engineCount;
}

int main()
{

    int x, y;
    cin >> x >> y;

    vector<vector<pair<int, bool>>> map(y, vector<pair<int, bool>>(x));
    for (int ys = 0; ys < y; ys++)
    {
        for (int xs = 0; xs < x; xs++)
        {
            pair<int, bool> sq;
            cin >> sq.first >> sq.second;
            map[ys][xs] = sq;
        }
    }

    cout << powodz(map) << endl;

    for (vector<pair<int, bool>> row : map)
    {
        row.clear();
    }
    map.clear();
}