/*
    T(n, m) = Θ((n + m) logn)
    M(n, m) = Θ(n + m).

    n - vertices
    m - edges
*/

class CompareDist {
   public:
    bool operator()(edge const &e1, edge const &e2) {
        if (e1.second > e2.second) return true;
        if (e1.second < e2.second) return false;
        return e1.first > e2.first;
    }
};

vector<float> dijkstra(int v) {
    vector<bool> visited(size(), false);
    vector<float> dist(size(), HUGE_VALF);
    priority_queue<edge, vector<edge>, CompareDist> q;
    q.push(make_pair(v, 0.0));
    while (!q.empty()) {
        edge p = q.top();
        int u = p.first;
        float d = p.second;
        q.pop();
        if (!visited[u]) {
            dist[u] = d;
            visited[u] = true;
            for (edge e : neighbours(u)) {
                q.push(make_pair(e.first, e.second + d));
            }
        }
    }
    return dist;
}