#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<vector<char>> s(5, vector<char>(n));
	vector<vector<int>> list(4, vector<int>(n));
	for(int i = 0; i < 5; i++)for(int j =0; j < n; j++){
		cin >> s[i][j];
		if(s[i][j] == 'R')list[0][j]++;
		if(s[i][j] == 'B')list[1][j]++;
		if(s[i][j] == 'W')list[2][j]++;
		if(s[i][j] == '#')list[3][j]++;
	}
	vector<vector<int>> dp(n+1, vector<int>(4, 1<<30));
	for(int i = 0; i < 4; i++)dp[0][i] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++)
				if(j != k)dp[i][j] = min(dp[i-1][k]+(5-list[j][i-1]), dp[i][j]);
		}
	}
	int ans = 1<<30;
	for(int i = 0; i < 4; i++)ans = min(dp[n][i], ans);
	cout << ans << endl;
}
