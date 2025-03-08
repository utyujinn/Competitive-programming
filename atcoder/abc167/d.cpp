#include<iostream>
using namespace std;
int N;
long K;
int A[2<<17];
bool seen[2<<17];
bool loop[2<<17];

void dfs(int c){
	if(loop[c])return;
	if(seen[c])loop[c]=true;
	seen[c]=true;
	dfs(A[c]);
}
pair<int,int> dfs2(int c){
	if(loop[c])return make_pair(c,0);
	else {
		auto [v,depth]=dfs2(A[c]);
		return make_pair(v,depth+1);
	}
}
void dfs3(int c,int depth){
	if(depth==K){
		cout<<c+1<<endl;
		return;
	}
	else dfs3(A[c],depth+1);
}

int main(){
	cin>>N>>K;
	for(int i=0;i<N;i++){
		cin>>A[i];A[i]--;
	}
	dfs(0);
	int cnt=0;
	for(int i=0;i<N;i++){
		if(loop[i])cnt++;
	}
	auto[v,depth]=dfs2(0);
	if(K<depth){
		dfs3(0,0);
	}else{
		K-=depth;
		K%=cnt;
		dfs3(v,0);
	}
}
