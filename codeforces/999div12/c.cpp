#include<iostream>
#include<vector>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	vector<long> dp(n);
	vector<long> dp2(n);
	if(n > 1){
		cin >> a[0] >> a[1];
		dp[0] = (a[0]==0)?1:0;
		dp[1] = ((a[0]==0&&a[1]==0) || a[1]==1)?1:0;
		dp2[0] = 1;
		dp2[1] = (a[0]==0)?1:0;
		for(int i = 2; i < n; i++){
			cin >> a[i];
			dp[i] += (a[i]==a[i-1])?dp[i-1]:0;
			dp[i] += (a[i]==a[i-2]+1)?dp2[i-1]:0;
			dp2[i] = dp[i-1];
			dp[i] %= 998244353;
			dp2[i] %= 998244353;
		}
		cout << (dp[n-1]+dp2[n-1])%998244353 << endl;
	}
	else{
		cin >> a[0];
		if(a[0]==0)cout << 2 << endl;
		else cout << 1 << endl;
	}
}

int main(){
	int t;
	cin >> t;
	for(;t--;)solve();
}
