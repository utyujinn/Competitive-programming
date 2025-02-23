#include<iostream>
#include<vector>
using namespace std;

int dfs(vector<vector<int>>&G, vector<int> &seen, int c, int depth){
	if(depth==0){
		long ret=0;
		for(auto n:G[c]){
			if(G[n].size()==3&&!seen[n]){
				seen[n]++;
				ret+=dfs(G,seen,n,depth+1);
				seen[n]--;
			}
		}
		return ret;
	}else{
		long ret=0;
		for(auto n:G[c]){
			if(G[n].size()==3&&!seen[n]){
				seen[n]++;
				ret+=dfs(G,seen,n,depth+1);
				seen[n]--;
			}else if(G[n].size()==2&&!seen[n]){
				ret+=1;
			}
		}
		return ret;
	}
}

int main(){
	int N;
	cin>>N;
	vector<vector<int>> G(N,vector<int>());
	for(int i=0;i<N-1;i++){
		int u,v;
		cin>>u>>v;
		u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	long ans=0;
	vector<int> seen(N);
	for(int i=0;i<N;i++){
		if(G[i].size()==2){
			seen[i]++;
			ans+=dfs(G,seen,i,0);
			seen[i]--;
		}
	}
	cout<<ans/2<<endl;
}
