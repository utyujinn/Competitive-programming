#include<iostream>
#include<vector>

using namespace std;

int main(){
	int v,e;
	cin >> v >> e;
	int s,t,d;
	vector<vector<int>> G(v, vector<int>(v, 1<<29));
	for(int i = 0; i < e; i++){
		cin >>  s >> t >> d;
		G[s][t] = d;
	}
	vector<vector<int>> dp(1<<v, vector<int> (v,1<<29));
	dp[0][0] = 0;
	for(int i = 0; i < 1<<v; i++){
		for(int j = 0; j < v; j++){
			if(i & 1<<j){
				for(int k = 0; k < v; k++){
					if(k!=j){
						dp[i][j] = min(dp[i^(1<<j)][k] + G[k][j], dp[i][j]);
					}
				}
			}
		}
	}
	if(dp[(1<<v)-1][0] == 1<<29)cout << -1 << endl;
	else cout << dp[(1<<v)-1][0] << endl;
}

	
