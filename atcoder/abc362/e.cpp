#include<iostream>
#include<map>
using namespace std;
map<int,int> dp[81][80];
int N;
int A[80];

int MOD=998244353;
int main(){
	cin>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			dp[2][j][A[j]-A[i]]++;
		}
	}
	for(int i=2;i<N;i++){
		for(int j=i-1;j<N;j++){
			for(auto[diff,cnt]:dp[i][j]){
				for(int k=j+1;k<N;k++){
					if(A[k]-A[j]==diff){
						dp[i+1][k][diff]=(dp[i+1][k][diff]+cnt)%MOD;
					}
				}
			}
		}
	}
	if(N==1)cout<<N<<" ";
	else cout<<N<<" "<<N*(N-1)/2<<" ";
	for(int i=3;i<=N;i++){
		int ans=0;
		for(int j=0;j<N;j++){
			for(auto[diff,cnt]:dp[i][j]){
				ans=(cnt+ans)%MOD;
			}
		}
		cout<<ans<<" ";
	}
	cout<<endl;
}
