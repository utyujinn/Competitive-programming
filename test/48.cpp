#include<iostream>
#include<vector>
using namespace std;

void solve(int n){
	vector<int> w(n);
	for(int i = 0; i < n; i++){
		cin >> w[i];
	}
	vector<vector<int>> dp(n, vector<int>(n, 0));
	for(int l = 2; l <= n; l++){
		for(int s = 0; s < n-l+1; s++){
			int e = s+l-1;
			if(dp[s+1][e-1] == l-2 && abs(w[s]-w[e])<=1)dp[s][e] = l;
			for(int k = s; k < s+l-1; k++){
				dp[s][e] = max(dp[s][e], dp[s][k] + dp[k+1][e]);
			}
		}
	}
	cout << dp[0][n-1] << endl;
}

int main(){
	int n;
	cin >> n;
	while(n!= 0){
		solve(n);
		cin >> n;
	}
}
