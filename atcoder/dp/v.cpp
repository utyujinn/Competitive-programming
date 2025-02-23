#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<long> G[1<<17];
vector<long> dp[1<<17];
long N,M;

long dfs(long v,long p){
	long s=G[v].size();
	dp[v].assign(s,-1);
	long ret=1;
	for(long i=0;i<s;i++){
		long to=G[v][i];
		if(to!=p){
			dp[v][i]=(dfs(to,v)+1)%M;
			ret=ret*dp[v][i]%M;
		}
	}
	return ret%M;
}

void wfs(long v,long pval,long p){
	long s=G[v].size();
	for(long i=0;i<s;i++){
		long to=G[v][i];
		if(to==p){
			dp[v][i]=(pval+1)%M;
		}
	}
	vector<long> left(s,1),right(s,1);
	for(long i=1;i<s;i++){
		left[i]=left[i-1]*dp[v][i-1]%M;
		right[i]=right[i-1]*dp[v][s-i]%M;
	}
	for(long i=0;i<s;i++){
		long to=G[v][i];
		if(to!=p){
			wfs(to,left[i]*right[s-i-1]%M,v);
		}
	}
	return;
}

void solve(){
	dfs(0,-1);
	wfs(0,0,-1);
	for(long i=0;i<N;i++){
		long ans=1;
		for(long j=0;j<dp[i].size();j++){
			ans=ans*dp[i][j]%M;
		}
		cout<<ans<<endl;
	}
}

int main(){
	cin>>N>>M;
	for(long i=0;i<N-1;i++){
		long x,y;
		cin>>x>>y;
		x--,y--;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	solve();
}
