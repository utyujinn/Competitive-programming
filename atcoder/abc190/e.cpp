#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<int>> G(n,vector<int>(0));
	for(int i = 0; i < m; i++){
		int a,b;
		cin >> a >> b ;
		a--;b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int K;
	cin >> K;
	vector<int> c(n);
	for(int i = 0; i < K; i++){
		cin >> c[i];
		c[i]--;
	}
	
	vector<vector<int>> cost(K, vector<int>(K,1e9));
	
	for(int i = 0; i < K; i++){
		queue<int> Q;
		vector<int> visited(n,1e9);
		Q.push(c[i]);
		visited[c[i]] = 0;
		while(!Q.empty()){
			int u = Q.front(); Q.pop();
			for(int v: G[u]){
				if(visited[v] == 1e9){
					visited[v] = visited[u]+1;
					Q.push(v);
				}
			}
		}
		for(int j = 0; j < K; j++){
			cost[i][j] = visited[c[j]];
		}
	}

	vector<vector<int>> dp(K, vector<int>(1<<K,1e9));
	
	for(int i = 0; i < K; i++)dp[i][1<<i] = 1;

	for(int i = 0; i < 1<<K; i++){
		for(int j = 0; j < K; j++){
			for(int k = 0; k < K; k++){
				dp[j][i | 1<<j] = min(dp[k][i] + cost[k][j], dp[j][i | 1<<j]);
			}
		}
	}
	int I = 0;
	I+=(1<<K)-1;
	int ans = 1e9;
	for(int i = 0; i < K; i++){
		if(ans > dp[i][I])ans = dp[i][I];
	}
	if(ans == 1e9)cout << -1 << endl;
	else cout << ans << endl;
}
