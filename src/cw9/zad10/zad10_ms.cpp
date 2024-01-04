#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <array>
#include <map>

using namespace std;

typedef struct nd *Graph;
struct nd
{
    int id;
    vector<Graph> edges;
};

struct dist
{
    array<int, 3> distances = {-1, -1, -1};
};
typedef struct dist triple;

Graph create_graph(int id)
{
    Graph newNode = (Graph)malloc(sizeof(nd));
    newNode->id = id;
    vector<Graph> edges;
    newNode->edges = edges;
    return newNode;
}

vector<Graph> init_graph(int n)
{
    vector<Graph> graphs(n);
    for (int i = 0; i < n; i++)
    {
        graphs[i] = create_graph(i);
    }
    return graphs;
}

void connect(Graph a, Graph b)
{
    a->edges.push_back(b);
    b->edges.push_back(a);
}

void connect(const vector<Graph> graphs, int a, int b)
{
    connect(graphs[a], graphs[b]);
}

bool was_visited(const set<int> visitHistory, int id)
{
    return visitHistory.find(id) != visitHistory.end();
}

void visit(set<int> &visitHistory, int id)
{
    visitHistory.insert(id);
}

bool is_valid_array(array<int, 3> arr)
{
    for (int c : arr)
    {
        if (c == -1)
            return false;
    }
    return true;
}

int sum_array(array<int, 3> arr)
{
    int sm = 0;
    for (int i = 0; i<3; i++)
    {
        sm += arr[i];
    }
    return sm;
}

template <typename T>
void plan_visit(int id, T g, queue<T> &toBeVisited, set<int> &visitHistory)
{
    if (!was_visited(visitHistory, id))
    {
        visit(visitHistory, id);
        toBeVisited.push(g);
    }
}

int polaczenie(const Graph &g, int u, int v, int w)
{
    Graph uG = NULL, vG = NULL, wG = NULL;
    // find u,v w
    queue<Graph> toBeVisited;
    set<int> visitHistory;
    plan_visit(g->id, g, toBeVisited, visitHistory);
    while (!toBeVisited.empty())
    {
        Graph currentGraph = toBeVisited.front();
        toBeVisited.pop();
        // plan next nodes to be visited
        for (Graph edge : currentGraph->edges)
        {
            plan_visit(edge->id, edge, toBeVisited, visitHistory);
        }

        if (currentGraph->id == u)
        {
            uG = currentGraph;
        }
        if (currentGraph->id == v)
        {
            vG = currentGraph;
        }
        if (currentGraph->id == w)
        {
            wG = currentGraph;
        }
    }

    if (uG == NULL || vG == NULL || wG == NULL)
    {
        return -1;
    }

    vector<Graph> startPoints = {uG, vG, wG};
    map<int, triple> distances;
    for (int i = 0; i < 3; i++)
    {
        queue<pair<Graph, int>> q;
        visitHistory.clear();
        plan_visit(startPoints[i]->id, make_pair(startPoints[i], 0), q, visitHistory);

        while (!q.empty())
        {
            pair<Graph, int> curr = q.front();
            q.pop();

            Graph graph = curr.first;
            int distance = curr.second;

            for (Graph edge : graph->edges)
            {
                pair<Graph, int> toBePlanned = make_pair(edge, distance + 1);
                plan_visit(edge->id, toBePlanned, q, visitHistory);
            }

            distances[graph->id].distances[i] = distance;
        }
    }

    cout << endl;

    int minEdges = INT32_MAX-1;
    for (auto dist : distances)
    {
        array<int,3> d = dist.second.distances;

        if (!is_valid_array(d))
            continue;
        int sum = sum_array(d);
        if (sum < minEdges)
        {
            minEdges=sum;
        }
    }

    return minEdges;
}

int main()
{
    vector<Graph> graph = init_graph(6);
    connect(graph, 0, 1);
    //connect(graph, 0, 4);
    //connect(graph, 0, 5);
    connect(graph, 1, 5);
    connect(graph, 1, 2);
    connect(graph, 2, 5);
    //connect(graph, 2, 3);
    connect(graph, 3, 5);
    connect(graph, 3, 4);
    connect(graph, 4, 5);

    cout << polaczenie(graph[0], 0, 2, 4) << endl;
}