#include <queue>
#include <utility>
#include <vector>

class Graph {
   public:
    typedef std::pair<int, float> edge;

   private:
    int n_vertices = 0;
    std::vector<std::vector<edge>> edges{};

   public:
    Graph(int n) {
        n_vertices = n;
        for (int i = 0; i < n; i++) {
            edges.push_back(std::vector<edge>{});
        }
    }
    int size() {
        return n_vertices;
    }

    void insert_directed_edge(int v1, int v2, float len) {
        edges[v1].push_back(std::make_pair(v2, len));
    }

    void insert_directed_edge(int v1, int v2) {
        insert_directed_edge(v1, v2, 1.0);
    }

    void insert_edge(int v1, int v2, float len) {
        insert_directed_edge(v1, v2, len);
        insert_directed_edge(v2, v1, len);
    }

    void insert_edge(int v1, int v2) {
        insert_edge(v1, v2, 1.0);
    }

    std::vector<edge> neighbours(int v) {
        return edges[v];
    }

    std::vector<std::vector<int>> search() {
        std::vector<bool> visited(size(), false);
        std::vector<std::vector<int>> result{};
        for (int v = 0; v < n_vertices; v++) {
            if (!visited[v]) {
                std::deque<int> q{v};
                std::vector<int> component{};
                visited[v] = true;
                while (!q.empty()) {
                    int u = q.front();
                    q.pop_front();
                    component.push_back(u);
                    for (std::pair<int, float> e : neighbours(u)) {
                        int w = e.first;
                        if (!visited[w]) {
                            visited[w] = true;
                            q.push_back(w);
                        }
                    }
                }
                result.push_back(component);
            }
        }
        return result;
    }
};

class CompareDist {
   public:
    bool operator()(Graph::edge const &e1, Graph::edge const &e2) {
        return e1.first > e2.first;
    }
};

int get_longest_increasing_path_length(Graph g) {
    int next_element;
    bool *visited = new bool[g.size()]{false};
    // std::pair<path_length, node_number>
    std::priority_queue<std::pair<int, int>, CompareDist> path;
    // minimal element: 0
    
    for (int i = 0; i < g.size(); i++) {
        if (visited[i])
            continue;

        path.push(std::make_pair(0, 0));
        while (!path.empty()) {
            //...
        }
    }
}