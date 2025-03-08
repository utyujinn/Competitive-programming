#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int N;
int B[14][1594323];
int dp[14][1594323];

int main(){
	cin>>N;
	for(int i=0;i<(int)pow(3,N);i++){
		char a;cin>>a;
		B[0][i]=a-'0';
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<(int)pow(3,(N-i-1));j++){
			int tmp=0;
			for(int k=j*3;k<j*3+3;k++){
				tmp+=B[i][k];
			}
			B[i+1][j]=(tmp>=2?1:0);
		}
	}
	if(B[N][0]==1)for(int i=0;i<(int)pow(3,N);i++)B[0][i]^=1;
	for(int i=0;i<(int)pow(3,N);i++){
		dp[0][i]=B[0][i]^1;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<(int)pow(3,(N-i-1));j++){
			vector<int> list;
			for(int k=j*3;k<j*3+3;k++){
				list.push_back(dp[i][k]);
			}
			sort(list.begin(),list.end());
			dp[i+1][j]=list[0]+list[1];
		}
	}
	cout<<dp[N][0]<<endl;
}
