#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> dp(n+1,1<<30);
	int ans = 0;
	dp[0] = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		int ok = n, ng = 0;
		while(ok-ng>1){
			int mid = (ok+ng)/2;
			if(dp[mid] >= a[i])ok = mid;
			else ng = mid;
		}
		dp[ok] = a[i];
		ans = max(ans, ok);
	}
	cout << ans << endl;
}
