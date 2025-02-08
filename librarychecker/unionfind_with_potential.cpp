#include<iostream>
#include<vector>
using namespace std;

struct UnionFind{
	long n;
	vector<long> size, parent;
	UnionFind(long n): size(n, 1), parent(n, -1){}
	long root(long x){
		if(parent[x] == -1)return x;
		else return root(parent[x]);
	}
	bool same(long x, long y){
		return root(x) == root(y);
	}
	void unite(long x, long y){
		if(same(x,y))return;
		long rx = root(x), ry = root(y);
		long connected = size[rx] * size[ry];
		if(size[rx] > size[ry]){
			parent[ry] = rx;
			size[rx] += size[ry];
		}
		else{
			parent[rx] = ry;
			size[ry] += size[rx];
		}
		return;
	}
	int groups(){
		int ret = 0;
		for(int i = 0; i < n; i++){
			if(parent[i] == -1)ret++;
		}
		return ret;
	}
};

int main(){
	int N,Q;
	cin>>N>>Q;
	UnionFind uf(N);
	for(;Q--;)
	{
		int t,u,v;
		cin>>t>>u>>v;
		if(t==0){
			int x;
			cin>>x;
			uf.unite(u,v);
		}
		if(t==1)cout<<(uf.same(u,v)?1:0)<<endl;
	}
}
