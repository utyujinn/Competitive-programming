#include<iostream>
#include<vector>
using namespace std;
long N,M,K;
int dp[2<<17];
int X[50],Y[50];
int MOD=998244353;

int main(){
	cin>>N>>M>>K;
	for(int i=0;i<M;i++){
		cin>>X[i]>>Y[i];
		X[i]--,Y[i]--;
	}
	dp[0]=1;
	vector<pair<int,int>> list;
	for(int i=0;i<K;i++){
		for(int j=0;j<M;j++){
			list.push_back(make_pair((Y[j]-i-1+N*K)%N,dp[(X[j]-i+N*K)%N]));
		}
		for(auto[to,cost]:list){
			dp[to]=(dp[to]+cost)%MOD;
		}
		list.clear();
	}
	int ans=0;
	for(int i=0;i<N;i++){
		ans=(ans+dp[i])%MOD;
	}
	cout<<ans<<endl;
}
