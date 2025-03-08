#include<iostream>
using namespace std;
int dp[101][501][501];
int N;
int A[100],B[100];

int main(){
	cin>>N;
	int sum=0;
	for(int i=0;i<N;i++){
		cin>>A[i]>>B[i];
		sum+=B[i];
	}
	if(sum%3!=0){
		cout<<-1<<endl;
		return 0;
	}
	sum/=3;
	for(int i=0;i<=N;i++)for(int j=0;j<=sum;j++)for(int k=0;k<=sum;k++)
		dp[i][j][k]=1500;
	dp[0][0][0]=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<=sum;j++){
			for(int k=0;k<=sum;k++){
				if(A[i]==1){
					if(j+B[i]<=sum)
						dp[i+1][j+B[i]][k]=min(dp[i+1][j+B[i]][k],dp[i][j][k]);
					if(k+B[i]<=sum)
						dp[i+1][j][k+B[i]]=min(dp[i+1][j][k+B[i]],dp[i][j][k]+1);
					dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j][k]+1);
				}else if(A[i]==2){
					if(j+B[i]<=sum)
						dp[i+1][j+B[i]][k]=min(dp[i+1][j+B[i]][k],dp[i][j][k]+1);
					if(k+B[i]<=sum)
						dp[i+1][j][k+B[i]]=min(dp[i+1][j][k+B[i]],dp[i][j][k]);
					dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j][k]+1);
				}else{
					if(j+B[i]<=sum)
						dp[i+1][j+B[i]][k]=min(dp[i+1][j+B[i]][k],dp[i][j][k]+1);
					if(k+B[i]<=sum)
						dp[i+1][j][k+B[i]]=min(dp[i+1][j][k+B[i]],dp[i][j][k]+1);
					dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j][k]);
				}
			}
		}
	}
	if(dp[N][sum][sum]==1500)cout<<-1<<endl;
	else cout<<dp[N][sum][sum]<<endl;
}
