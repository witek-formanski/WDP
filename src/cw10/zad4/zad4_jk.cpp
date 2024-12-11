/*
    O(n! * n) solution with backtracking (without any optimisations)
    Author: Jan Kwieciński

    Possible optimisation: looking at the bitmask of the already constructed path
    (For example paths 0-2-1 and 0-1-2 can be continued in the same way, which is counted twice in the solution below)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    Solution(vector<pair<int, int>> _r, vector<vector<int>> _w) : n(_w.size()), rest_inp(_r), weights(_w)
    {
        restrictions.resize(n, {});
        for (auto p : rest_inp) restrictions[p.second].push_back(p.first);
        for (int i = 0; i < n; i++) if (i != n-1) restrictions[n-1].push_back(i);
    }

    //solve can be run many times on the same input
    int solve()
    {
        answer = 0; 
        visited.resize(n, false); visited[0] = true;
        recurrent_solve(0, 0, 1);
        return answer;
    }
private:
    int n;
    vector<pair<int, int>> rest_inp; //restrictions input
    vector <vector<int>> restrictions; //parsed restrictions
    vector<vector<int>> weights;
    vector<bool> visited;
    int answer;

    void recurrent_solve(int curr, int len, int node_len)
    {
        if (restrictions_breach(curr)) return;
        if (node_len == n) {answer = max(answer, len); return;}

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                recurrent_solve(i, len + weights[curr][i], node_len+1);
                visited[i] = false;
            }
        }
    }

    bool restrictions_breach(int x)
    {
        for (auto y : restrictions[x]) if (!visited[y]) return true;
        return false;
    }
};

int main()
{
    vector <vector<int>> W = {{0, 2, 1, 1}, {2, 0, 400, 2}, {100, 1, 0, 1}, {100, 400, 1, 0}}; //(doesn't have to be symmetrical)
    vector <pair<int, int>> R = {make_pair(2, 1)};
    Solution rozw = Solution(R, W);
    assert(rozw.solve() == 4);
}