#include<iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	vector<vector<int>>G(N);
	for(int i=0;i<N-1;i++){
		int u,v;
		cin>>u>>v;
		u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

