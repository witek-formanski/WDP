#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int str, const vector<vector<int>> &adj){
	vector<int> dis(adj.size(), 1e8);
	vector<bool> vis(adj.size(), 0);
	queue<int> q;
	q.push({str});
	dis[str]=0;
	vis[str]=1;
	while(!q.empty()){
		int u=q.front(); q.pop();
		for (auto v : adj[u]){
			if(vis[v]) continue;
			dis[v]=dis[u]+1;
			vis[v]=1;
			q.push(v);
		}
	}
	return dis;
}

int polaczenie(const vector<vector<int>> &adj, int u, int v, int w){
	vector<int> du=bfs(u, adj), dv=bfs(v, adj), dw=bfs(w, adj);
	int dis=1e8-1;
	for (int i=0; i<adj.size(); ++i)
		dis=min(dis, du[i]+dv[i]+dw[i]);
	return dis==1e8-1?-1:dis;
}
