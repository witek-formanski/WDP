#define LEFT_EDGE -1
#define RIGHT_EDGE 1
#define BOTTOM_EDGE -1
#define TOP_EDGE 1
#define NONE_EDGE 0

#include <iostream>
#include <vector>
#include <map>

using namespace std;

enum HexType
{
    White = 0,
    Black = 1
};

typedef struct p *Point;
struct p
{
    int x;
    int y;
};

typedef struct h *Hex;
struct h
{
    HexType type;
    Point furthest1;
    Point furthest2;
};

Hex make_hex(HexType t, Point f1, Point f2)
{
    Hex newHex = (Hex)malloc(sizeof(h));
    newHex->furthest1 = f1;
    newHex->furthest2 = f2;
    newHex->type = t;
    return newHex;
}

Point make_point(int x, int y)
{
    Point newPoint = (Point)malloc((sizeof(p)));
    newPoint->x = x;
    newPoint->y = y;
    return newPoint;
}

Point make_point(pair<int, int> cords)
{
    return make_point(cords.first, cords.second);
}

const int MAX_NEIGHBOURS_COUNT = 6;
const int Dx[] = {-1, 0, -1, 1, 0, 1};
const int Dy[] = {-1, -1, 0, 0, 1, 1};

bool are_valid_cords(int x, int y, int n)
{
    return x >= 0 && y >= 0 && x < n && y < n;
}

bool is_full_path(Hex a, int n, bool horizontal)
{
    int f = horizontal ? a->furthest1->x : a->furthest1->y;
    int s = horizontal ? a->furthest2->x : a->furthest2->y;
    return f == 0 && s == n - 1;
}

bool is_before(Point a, Point b, bool horizontal)
{
    if (horizontal)
        return a->x < b->x;
    return a->y < b->y;
}

// let: current->furthest1 is yer hex's cords
bool try_get_neighbour(Hex current, int nX, int nY, int n, map<pair<int, int>, Hex> &map, Hex *results)
{
    pair<int, int> neighbourCords = make_pair(nX, nY);
    if (!are_valid_cords(nX, nY, n))
        return false;
    *results = map[neighbourCords];
    return *results != NULL && (*results)->type == current->type;
}

// T(n) = O(m * log(n)), m - moves count
// M(n) = O(m)
int game(int n, const vector<pair<int, int>> &moves)
{
    if (n <= 0)
        return 0;

    int results = 0;

    // map with all colored hexes
    map<pair<int, int>, Hex> map;
    // to avoid Point being garbage-collected
    vector<Point> cordsList;

    bool isWhitesTurn = false;
    for (int m = 0; m < (int)moves.size(); m++)
    {
        isWhitesTurn = !isWhitesTurn;
        pair<int, int> moveCords = moves[m];
        cordsList.push_back(make_point(moveCords));
        Point currentCords = cordsList[m];

        Hex currentHex = make_hex(isWhitesTurn ? White : Black, currentCords, currentCords);
        map[moveCords] = currentHex;

        // update neightbours data
        vector<Hex> neighbours;
        for (int neightbourId = 0; neightbourId < MAX_NEIGHBOURS_COUNT; neightbourId++)
        {
            int nX = currentCords->x + Dx[neightbourId], nY = currentCords->y + Dy[neightbourId];
            Hex neightbour = NULL;
            if (!try_get_neighbour(currentHex, nX, nY, n, map, &neightbour))
            {
                // wrong cords or opponent's/no one's hex
                continue;
            }
            // is neighbour
            neighbours.push_back(neightbour);

            // find furthest point in the axis
            if (is_before(neightbour->furthest1, currentHex->furthest1, isWhitesTurn))
            {
                currentHex->furthest1 = neightbour->furthest1;
            }
            if (is_before(currentHex->furthest2, neightbour->furthest2, isWhitesTurn))
            {
                currentHex->furthest2 = neightbour->furthest2;
            }
        }

        // update neighbours' info
        for (Hex currN : neighbours)
        {
            currN->furthest1 = currentHex->furthest1;
            currN->furthest2 = currentHex->furthest2;
        }
        neighbours.clear();

        if (is_full_path(currentHex, n, isWhitesTurn))
        {
            int sign = isWhitesTurn ? 1 : -1;
            results = (m + 1) * sign;
            break;
        }
    }

    cordsList.clear();
    map.clear();

    return results;
}

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<pair<int, int>> moves(k);
    for (int m = 0; m < k; m++)
    {
        cin >> moves[m].first >> moves[m].second;
    }

    int winner = game(n, moves);
    cout << winner << endl;
    moves.clear();
    return 0;
}