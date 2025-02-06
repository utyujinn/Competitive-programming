#include<iostream>
#include<vector>
using namespace std;

void dfs(int c, int d, vector<vector<int>> &parent, vector<int> &dist, vector<vector<int>> G){
	dist[c] = d;
	for(int next : G[c]){
		if(dist[next] == -1){
			parent[next][0] = c;
			dfs(next,d+1,parent, dist, G);
		}
	}
}

int main(){
	int n;
	cin >> n;
	int k = 1;
	while(1<<k < n){
		k++;
	}
	k--;
	vector<vector<int>> G(n);
	int x,y;
	for(int i = 0; i < n-1; i++){
		cin >> x >> y;
		x--,y--;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	vector<vector<int>> parent(n, vector<int>(k,-1));
	vector<int> dist(n,-1);

	dfs(0, 0, parent, dist, G);

	for(int i = 1; i < k; i++){
		for(int j = 0; j < n; j++){
			if(parent[j][i-1] != -1){
				parent[j][i] = parent[parent[j][i-1]][i-1];
			}	
		}
	}
	int q;
	cin >> q;
	int a,b;
	for(;q--;){
		cin >> a >> b;
		a--,b--;
		int da = dist[a], db = dist[b];
		if(dist[a] < dist[b])swap(a,b);
		int tmp = 0;
		while(dist[a] != dist[b]){
			int tmp2 = ((dist[a]-dist[b])>>tmp)&1;
			if(tmp2)a = parent[a][tmp];
			//a = parent[a][((dist[a]-dist[b]) & (1<<tmp))-1];
			tmp++;
			if(tmp == k)break;
		}
		tmp = k-1;
		while(parent[a][0]!=parent[b][0]){
			if(parent[a][tmp] == -1){
			} else if(parent[a][tmp] == parent[b][tmp]){
			} else{
				a = parent[a][tmp];
				b = parent[b][tmp];
			}
			tmp--;
			if(tmp == -1)break;
		}
		a = parent[a][0], b=parent[b][0];
		cout << da+db-dist[a]*2+1 << endl;
	}
}
