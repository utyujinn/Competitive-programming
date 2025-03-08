#include<iostream>
using namespace std;
int a[2<<17];
int G[2<<17];
bool seen[2<<17],loop[2<<17];

int dfs(int idx){
	if(!seen[G[idx]])
}

int main(){
	int N;cin>>N;
	for(int i=0;i<N;i++){
		cin>>a[i];
		a[i]--;
		G[i]=a[i];
	}
	for(int i=0;i<N;i++){
		if(!seen[i]){
			dfs(i);
		}
	}
}
