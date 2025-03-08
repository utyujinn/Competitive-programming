#include<iostream>
#include<vector>
using namespace std;
int N,K;
vector<int> G[2<<17];
bool V[2<<17];

int bfs(int c,int p){
	int ret=0;
	for(int n:G[c]){
		if(n!=p){
			ret+=bfs(n,c);
		}
	}
	if(ret==0)return V[c];
	else return ret+1;
}

int main(){
	cin>>N>>K;
	for(int i=0;i<N-1;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int s;
	cin>>s;
	V[--s]=true;
	for(int i=0;i<K-1;i++){
		int v;cin>>v;
		v--;
		V[v]=true;
	}
	cout<<bfs(s,-1)<<endl;
}
