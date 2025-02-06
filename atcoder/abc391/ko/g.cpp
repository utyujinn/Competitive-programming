#include<iostream>
using namespace std;
int N,M;
string S;
int dp[101][11];
int main(){
	cin>>N>>M>>S;
	dp[0][0]=1;
	for(int i=0;i<M;i++)for(int j=0;j<=N;j++)
	{
		if(j==N)dp[i+1][j]+=dp[i][j]*26;
		else
		{
			dp[i+1][j+1]+=dp[i][j];
			dp[i+1][j]+=dp[i][j]*25;
		}
	}
	for(int j=0;j<=N;j++)cout<<dp[M][j]<<(j==N?"\n":" ");
}
