#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int>> &G, vector<int> &dist, int c){
	for(int next: G[c]){
		dist[next] = dist[c]+1;
		dfs(G, dist, next);
	}
}

int main(){
	int n;
	int k;
	int a = 0;
	int c;
	cin >> n;
	while(1<<a < n){
		a++;
	}
	vector<vector<int>> G(n);
	vector<vector<int>> parent(n,vector<int>(a,-1));
	for(int i = 0 ;i < n; i++){
		cin >> k;
		for(;k--;){
			cin >> c;
			G[i].push_back(c);
			parent[c][0] = i;
		}
	}
	for(int j = 1; j < a; j++){
		for(int i = 0; i < n; i++){
			if(parent[i][j-1] >= 0)
				parent[i][j] = parent[parent[i][j-1]][j-1];
		}
	}
	vector<int> dist(n,0);
	dfs(G, dist, 0);
	int q;
	cin >> q;
	int u,v;
	for(int i = 0; i < q; i++){
		cin >> u >> v;
		if(dist[u] < dist[v]){
			swap(u,v);
		}
		for(int k = 0; k < a; k++){
			if((dist[u] - dist[v]) >> k & 1){
				u = parent[u][k];
			}
		}
		int ans;
		if(u==v){
			ans = u;
		}
		else {
			for(int k = a-1; k >= 0; k--){
				if(parent[u][k] != parent[v][k]){
					u = parent[u][k];
					v = parent[v][k];
				}
			}
			ans = parent[u][0];
		}
		cout << ans << endl;
	}
}
