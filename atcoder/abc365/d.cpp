#include<iostream>
#include<algorithm>
using namespace std;
int dp[3][2<<17];//R->0,P->1,S->2

int main(){
	int N;cin>>N;
	string S;cin>>S;
	for(int i=0;i<N;i++){
	if(S[i]=='R'){
		dp[0][i+1]=max(dp[1][i],dp[2][i])+0;
		dp[1][i+1]=max(dp[0][i],dp[2][i])+1;
		dp[2][i+1]=0;
	}else if(S[i]=='P'){
		dp[0][i+1]=0;
		dp[1][i+1]=max(dp[0][i],dp[2][i])+0;
		dp[2][i+1]=max(dp[0][i],dp[1][i])+1;
	}else if(S[i]=='S'){
		dp[0][i+1]=max(dp[1][i],dp[2][i])+1;
		dp[1][i+1]=0;
		dp[2][i+1]=max(dp[0][i],dp[1][i])+0;
	}
	}
	cout<<max({dp[0][N],dp[1][N],dp[2][N]})<<endl;

}
