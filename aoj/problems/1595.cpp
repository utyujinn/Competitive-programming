#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
vector<int> G[1<<17];
vector<int> dp[1<<17];
int ans[1<<17];

void pG(){
	for(int i=0;i<N;i++){
		cout<<i<<":";
		for(int j=0;j<G[i].size();j++){
			cout<<G[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void pdp(){
	for(int i=0;i<N;i++){
		cout<<i<<":";
		for(int j=0;j<dp[i].size();j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int rec(int v, int p=-1){
	int s=G[v].size();
	int res=0;
	dp[v].assign(s,-1);
	for(int i=0;i<s;i++){
		int to=G[v][i];
		if(to!=p){
			dp[v][i]=rec(to,v);
			res=max(res,dp[v][i]+1);
		}
	}
	return res;
}

void rerec(int v,int pval,int p){
	int s=G[v].size();
	//pdp();
	for(int i=0;i<s;i++){
		int to=G[v][i];
		if(to==p){
			dp[v][i]=pval;
		}
	}
	vector<int> left(s+1,-1),right(s+1,-1);
	for(int i=0;i<s;i++){
		left[i+1]=max(left[i],dp[v][i]);
		right[i+1]=max(right[i],dp[v][s-i-1]);
	}
	for(int i=0;i<s;i++){
		int to=G[v][i];
		if(to!=p){
			rerec(to, max(left[i],right[s-i-1])+1,v);
		}
	}
}

void solve(){
	rec(0,-1);
	rerec(0,0,-1);
	//pdp();
	for(int v=0;v<N;v++){
		int res=0;
		for(int i=0;i<G[v].size();i++){
			res=max(res,dp[v][i]+1);
		}
		cout<<(N-1)*2-res<<endl;
	}
}

int main(){
	cin>>N;
	for(int i=0;i<N-1;i++){
		int u,v;
		cin>>u>>v;
		u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	solve();
}	
