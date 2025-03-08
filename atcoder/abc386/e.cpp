#include<iostream>
#include<algorithm>
using namespace std;
int N,K;
long A[2<<17];
long ans;

void dfs(long cnt,int prev,int left){
	if(left==0){
		ans=max(ans,cnt);
	}else{
		for(int i=prev+1;i<N;i++){
			cnt^=A[i];
			dfs(cnt,i,left-1);
			cnt^=A[i];
		}
	}
}

int main(){
	cin>>N>>K;
	for(int i=0;i<N;i++)cin>>A[i];
	long cnt=0;
	if(K>N/2){
		K=N-K;
		for(int i=0;i<N;i++)cnt^=A[i];
	}
	dfs(cnt,-1,K);
	cout<<ans<<endl;
}
