#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int N;
vector<pair<int,int>> G[2<<17];
long dist[2<<17];

int main(){
	cin>>N;
	long ans=0;
	for(int i=0;i<N-1;i++){
		int a,b,c;cin>>a>>b>>c;
		a--,b--;
		G[a].emplace_back(b,c);
		G[b].emplace_back(a,c);
		ans+=c;
	}
	queue<pair<long,int>> q;
	q.emplace(0,0);
	for(int i=0;i<N;i++)dist[i]=~0ULL>>1;
	dist[0]=0;
	long mdist=0;
	int mu=0;
	while(!q.empty()){
		auto a=q.front();q.pop();
		long cost=a.first,v=a.second;
		for(auto n:G[v]){
			int ncost=n.second,u=n.first;
			if(dist[u]>cost+ncost){
				dist[u]=cost+ncost;
				if(mdist<dist[u]){
					mdist=max(dist[u],mdist);
					mu=u;
				}
				q.emplace(dist[u],u);
			}
		}
	}
	q.emplace(0,mu);
	for(int i=0;i<N;i++)dist[i]=~0ULL>>1;
	dist[mu]=0;
	while(!q.empty()){
		auto a=q.front();q.pop();
		long cost=a.first,v=a.second;
		for(auto n:G[v]){
			int ncost=n.second,u=n.first;
			if(dist[u]>cost+ncost){
				dist[u]=cost+ncost;
				if(mdist<dist[u]){
					mdist=max(dist[u],mdist);
					mu=u;
				}
				q.emplace(dist[u],u);
			}
		}
	}
	cout<<ans*2-mdist<<endl;
}
