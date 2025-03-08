#include<iostream>
#include<queue>
using namespace std;
struct edge{
	int to;
	int weight;
};
int A[2<<17];
vector<edge> G[2<<17];

int main(){
	int N,M;cin>>N>>M;
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=0;i<M;i++){
		int u,v,b;cin>>u>>v>>b;
		u--,v--;
		edge tmp={v,b};
		G[u].push_back(tmp);
		tmp={u,b};
		G[v].push_back(tmp);
	}
	priority_queue<pair<long,int>,vector<pair<long,int>>,greater<>> pq;
	vector<long> dist(N,~0ULL>>1);
	dist[0]=A[0];
	pq.emplace(A[0],0);
	while(!pq.empty()){
		auto[cost,v]=pq.top();pq.pop();
		if(dist[v]<cost)continue;
		for(auto[n,weight]:G[v]){
			if((long)A[n]+weight+cost<dist[n]){
				dist[n]=(long)A[n]+weight+cost;
				pq.emplace(dist[n],n);
			}
		}
	}
	for(int i=1;i<N;i++){
		cout<<dist[i]<<" ";
	}
	cout<<endl;
}
