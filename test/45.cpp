#include<iostream>
#include<vector>
using namespace std;

void solve(int n, int m){
	vector<int> c(m);
	vector<int> x(n);
	for(int i = 0; i < m; i++)cin >> c[i];
	for(int i = 0; i < n; i++)cin >> x[i];
	vector<vector<int>> dp(n+1, vector<int>(256, 1<<30));
	dp[0][128] = 0;
	for(int i = 1; i <= n;i++){
		for(int j = 0; j < m; j++){
			for(int k = 0; k < 256; k++){
				if(k+c[j] < 0){
					dp[i][0] = min(dp[i][0], dp[i-1][k] + x[i-1]*x[i-1]);
				}else if(k+c[j] >= 256){
					dp[i][255] = min(dp[i][255], dp[i-1][k] + (x[i-1]-255)*(x[i-1]-255));
				}else{
					dp[i][k+c[j]] = min(dp[i][k+c[j]], dp[i-1][k] + (x[i-1]-(k+c[j]))*(x[i-1]-(k+c[j])));
				}
			}
		}
	}
	int ans = 1<<30;
	for(int i = 0; i < 256; i++){
		ans = min(ans, dp[n][i]);
	}
	cout << ans << endl;
}

int main(){
	int n,m;
	cin >> n >> m;
	while(n != 0 || m != 0){
		solve(n,m);
		cin >> n >> m;
	}
}
