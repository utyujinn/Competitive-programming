#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct edge{
	int to;
	bool inv;
};
struct dt{
	int v;
	bool inv;
	long cost;
};
vector<edge> G[2<<17];
long dp[2][2<<17];

int main(){
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int N,M,X;
	cin>>N>>M>>X;
	for(int i=0;i<M;i++){
		int u,v;cin>>u>>v;
		u--,v--;
		edge tmp={v,true};
		G[u].push_back(tmp);
		tmp={u,false};
		G[v].push_back(tmp);
	}
	for(int i=0;i<N;i++){
		dp[0][i]=~0ULL>>1;
		dp[1][i]=~0ULL>>1;
	}
	dp[0][0]=0;
	dp[1][0]=X;
	auto compare=[](dt a,dt b){
		return a.cost>b.cost;
	};
	priority_queue<dt,vector<dt>,decltype(compare)> q{compare};
	dt tmp={0,true,0};
	q.emplace(tmp);
	tmp={0,false,X};
	q.emplace(tmp);
	while(!q.empty()){
		auto c=q.top();q.pop();
		if(c.inv&&dp[0][c.v]<c.cost)continue;
		if(!c.inv&&dp[1][c.v]<c.cost)continue;
		if(c.cost>min(dp[0][N-1],dp[1][N-1]))break;
		for(auto n:G[c.v]){
			if(!(c.inv^n.inv)){
				dt tmp={n.to,c.inv,c.cost+1};
				if(dp[!c.inv][n.to]>c.cost+1){
					dp[!c.inv][n.to]=c.cost+1;
					q.emplace(tmp);
				}
			}else{
				dt tmp={n.to,!c.inv,c.cost+1+X};
				if(dp[c.inv][n.to]>c.cost+1+X){
					dp[c.inv][n.to]=c.cost+1+X;
					q.emplace(tmp);
				}
			}
		}
	}
	cout<<min(dp[0][N-1],dp[1][N-1])<<endl;
}
