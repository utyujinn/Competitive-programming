#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> dp(k);
	for(int i = 0;i < k; i++){
		dp[i] = s[i]-'a';
	}
	for(int i = k; i < n; i++){
		int ok = k; ng = -1

