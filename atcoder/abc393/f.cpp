#include<iostream>
#include<tuple>
#include<algorithm>
#include<vector>
using namespace std;
int N,Q;
int A[2<<17];
int ans[2<<17];

int main(){
	cin>>N>>Q;
	for(int i=0;i<N;i++)cin>>A[i];
	vector<tuple<int,int,int>> RX(Q);
	for(int i=0;i<Q;i++){
		int r,x;
		cin>>r>>x;
		RX[i]=make_tuple(r,x,i);
	}
	sort(RX.begin(),RX.end());
	vector<int> dp(N+1,1<<30);
	dp[0]=0;
	int idx=0;
	for(int i=0;i<Q;i++){
		while(get<0>(RX[i])!=idx){
			int a=upper_bound(dp.begin(),dp.end(),A[idx])-dp.begin();
			if(dp[a-1]<A[idx])dp[a]=A[idx];
			idx++;
		}
		int tmp=upper_bound(dp.begin(),dp.end(),get<1>(RX[i]))-dp.begin();
		ans[get<2>(RX[i])]=tmp-1;
	}
	for(int i=0;i<Q;i++){
		cout<<ans[i]<<endl;
	}
}
