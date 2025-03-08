#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int N;cin>>N;
	vector<int> A(N);
	vector<pair<int,int>> dp(N+1,make_pair(~0U>>1,-1));
	int K=0;
	for(int i=0;i<N;i++){
		cin>>A[i];
		int id=lower_bound(dp.begin(),dp.end(),make_pair(A[i],0))-dp.begin();
		if(dp[id].first!=A[i])dp[id]=make_pair(A[i],i);
		K=max(K,id+1);
	}
	for(auto it=dp.begin();it->first!=~0U>>1;it++){
		cout<<it->first<<" ";
	}
	for(auto it=dp.begin();it->first!=~0U>>1;it++){
		cout<<it->second<<" ";
	}
	cout<<endl;
}
