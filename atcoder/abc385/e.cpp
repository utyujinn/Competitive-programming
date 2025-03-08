#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
int N;
vector<int> G[3<<17];
int sz[3<<17];

int main(){
	cin>>N;
	for(int i=0;i<N-1;i++){
		int u,v;cin>>u>>v;
		u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=0;i<N;i++){
		sz[i]=G[i].size();
	}
	int ans=0;
	for(int i=0;i<N;i++){
		vector<int> list;
		int msize=0;
		for(auto n:G[i]){
			msize=max(msize,sz[n]);
			list.push_back(sz[n]);
		}
		map<int,int> sizelist;
		for(auto n:G[i]){
			sizelist[sz[n]]++;
		}
		int x=0;
		auto it=sizelist.rbegin();
		while(it!=sizelist.rend()){
			int y=it->first-1;
			x+=it->second;
			ans=max(ans,1+x*(y+1));
			it++;
		}
	}
	cout<<N-ans<<endl;
}
