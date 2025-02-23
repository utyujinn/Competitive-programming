#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
	int N,M;
	cin>>N>>M;
	long ans=0;
	vector<set<int>> G(N);
	for(;M--;){
		int u,v;
		cin>>u>>v;
		u--,v--;
		if(u==v)ans++;
		else if(G[u].count(v))ans++;
		else{
			G[u].insert(v);
			G[v].insert(u);
		}
	}
	cout<<ans<<endl;
}
