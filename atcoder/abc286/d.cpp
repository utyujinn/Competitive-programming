#include<iostream>
using namespace std;

int dp[51][10010];

int main(){
	int n,x;
	cin >> n >> x;
	int a ,b; 
	for(int i = 0; i < n+1; i++){
		for(int j = 0; j <= x; j++){
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;
	for(int i =  0; i < n; i++){
		cin >> a >> b;
		for(int j = 0; j <= x; j++){
			if(dp[i][j] == 1){
				for(int k = 0; k <= b && j+k*a <= x; k++){
					dp[i+1][j+k*a] = 1;
				}
			}
		}
	}
	/*
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= x; j++){
		cout << dp[i][j] << " ";
		}
	cout << endl;
}
*/
	cout << (dp[n][x]?"Yes":"No") << endl;
}
	
