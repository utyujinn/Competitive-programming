#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,m;
	cin >> n >> m;
	vector<int> d(n),c(m);
	for(int i = 0; i < n; i++)cin >> d[i];
	for(int i = 0; i < m; i++)cin >> c[i];
	vector<vector<int>> dp(m+1, vector<int>(n+1, 1<<30));
	dp[0][0] = 0;
	for(int i = 1; i < m+1; i++){
		dp[i][0] = dp[i-1][0];
		for(int j = 1; j < n+1; j++){
			if(dp[i-1][j-1] != 1<<30)dp[i][j] = min(dp[i-1][j] , dp[i-1][j-1] + c[i-1]*d[j-1]);
		}
	}
	cout << dp[m][n] << endl;
}
