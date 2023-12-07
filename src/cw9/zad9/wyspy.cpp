#include <bits/stdc++.h>
using namespace std;

const int dx[]={0, 0, 1, -1};
const int dy[]={-1, 1, 0, 0};

bool ok(int y, int x, int n, int m){
	return x>=0&&x<m&&y>=0&&y<n;
}

int wyspy(vector<vector<bool>> &adj){
	int n=adj.size(), m=adj[0].size(), ans=0;
	vector<vector<bool>> vis(n, vector<bool>(m, 0));
	deque<array<int, 3>> dq;
	//vector<vector<int>> res(n, vector<int>(m, 0));
	for (int i=0; i<m; ++i){
		vis[0][i]=vis[n-1][i]=1;
		if(adj[0][i])
			dq.push_back({1, 0, i});
		else 
			dq.push_front({0, 0, i});
		if(adj[n-1][i])
			dq.push_back({1, n-1, i});
		else
			dq.push_front({0, n-1, i});
	}
	for (int i=0; i<n; ++i){
		vis[i][0]=vis[i][n-1]=1;
		if(adj[i][0])
			dq.push_back({1, i, 0});
		else 
			dq.push_front({0, i, 0});
		if(adj[i][m-1])
			dq.push_back({1, i, m-1});
		else
			dq.push_front({0, i, m-1});
	}
	while(!dq.empty()){
		array<int, 3> u=dq.front(); dq.pop_front();
		ans=max(ans, u[0]);
		for (int i=0; i<4; ++i){
			int y=u[1]+dy[i], x=u[2]+dx[i];
			if(!ok(y, x, n, m)||vis[y][x]) continue;
			vis[y][x]=1;
			if(adj[y][x]==adj[u[1]][u[2]]) dq.push_front({u[0], y, x});
			else dq.push_back({u[0]+1, y, x});
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<bool>> adj(n, vector<bool>(m, 0));
	for (int i=0; i<n; ++i){
		for (int j=0; j<m; ++j){
			int x;
			cin >> x;
			if(x) adj[i][j]=1;
		}
	}
	cout << wyspy(adj);
}
