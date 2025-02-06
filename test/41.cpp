#include<iostream>
#include<vector>
using namespace std;

int main(){
	int d,n;
	cin >> d >> n;
	vector<int> t(d);
	for(int i= 0; i < d; i++){
		cin >> t[i];
	}
	vector<int> a(n), b(n), c(n);
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	vector<vector<int>> dp(d+1,vector<int>(n,-1));
	for(int i = 0; i < n; i++){
		dp[0][i] = 0;
	}
	for(int i = 1;i <= d; i++){
		for(int j = 0; j < n; j++){
			if(a[j] <= t[i-1] && t[i-1] <= b[j]){
				for(int k = 0; k < n; k++){
					if(dp[i-1][k] != -1){
						if(i==1)dp[i][j] = 0;
						else dp[i][j] = max(dp[i-1][k] + abs(c[j]-c[k]), dp[i][j]);
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans = max(dp[d][i],ans);
	}
	for(int i = 0; i < d+1; i++){
		for(int j = 0; j < n; j++){
//			cout << dp[i][j] << " " ;
		}
//		cout << endl;
	}
	cout << ans << endl;
}
