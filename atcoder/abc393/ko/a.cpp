#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,Q;
int A[2<<17];
vector<pair<int,int> > qx[2<<17];
int ans[2<<17];
int dp[2<<17];

int main(){
	cin>>N>>Q;
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=0;i<Q;i++){
		int r,x;cin>>r>>x;
		qx[r-1].push_back(make_pair(x,i));
	}
	for(int i=0;i<=N;i++){
		dp[i]=2e9;
	}
	dp[0]=0;
	for(int i=0;i<N;i++)
	{
		int l=lower_bound(dp,dp+N,A[i])-dp;
		dp[l]=min(dp[l],A[i]);
		for(auto[x,id]:qx[i]){
			ans[id]=upper_bound(dp,dp+N+1,x)-dp;
		}
	}
	for(int i=0;i<Q;i++)cout<<ans[i]-1<<"\n";
}
