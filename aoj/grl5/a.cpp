#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct edge{
	int to,cost;
	edge(int t,int c):to(t),cost(c){}
};

vector<edge> G[1<<17];
int dist[1<<17];

void dfs(int idx,int par){
	for(auto &n:G[idx])if(n.to!=par){
		dfs(n.to,idx);
		dist[idx]=max(dist[idx], n.cost+dist[n.to]);
	}
}

int dfs2(int idx, int d_par, int par){
	vector<pair<int,int>> d_child;
	d_child.emplace_back(0,-1);
	for(auto &n:G[idx]){
		if(n.to==par)d_child.emplace_back(d_par+n.cost,n.to);
		else d_child.emplace_back(dist[n.to],n.to);
	}
	sort(d_child.rbegin(), d_child.rend());
	int ret=d_child[0].first+d_child[1].first;
	for(auto &n:G[idx]){
		if(n.to==par)continue;
		else ret=max(ret, dfs2(n.to,d_child[d_child[0].second==n.to].first,idx));
	}
	return ret;
}

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N-1;i++){
		int s,t,w;
		cin>>s>>t>>w;
		G[s].push_back(edge(t,w));
		G[t].push_back(edge(s,w));
	}
	dfs(0,-1);
	cout<<dfs2(0,0,-1)<<endl;
}


