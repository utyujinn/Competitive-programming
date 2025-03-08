#include<iostream>
using namespace std;
int N;
long dp[2];
int main(){
	cin>>N;
	dp[0]=0;
	dp[1]=-2e9;
	for(;N--;){
		long a;cin>>a;
		long dp0=dp[0]+a;
		long dp1=dp[1]+a*2;
		dp[0]=max(dp1,dp[0]);
		dp[1]=max(dp0,dp[1]);
	}
	cout<<max(dp[0],dp[1])<<endl;
}
