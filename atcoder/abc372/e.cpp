#include<iostream>
#include<set>
#include<vector>
using namespace std;

struct UnionFind{
	int n;
	vector<long> size, parent;
	vector<set<int>> s;
	UnionFind(long n): s(n),size(n, 1), parent(n, -1){
		for(int i=0;i<n;i++){
			s[i].insert(i);
		}
	}
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
			s[rx].insert(s[ry].begin(),s[ry].end());
		}
		else{
			parent[rx] = ry;
			size[ry] += size[rx];
			s[ry].insert(s[rx].begin(),s[rx].end());
		}
		return;
	}
	int getk(long v,long k){
		int rv=root(v);
		if(s[rv].size()<k)return -1;
		auto it=s[rv].end();
		advance(it,-k);
		return *it+1;
	}
};

int main(){
	int N,Q;
	cin>>N>>Q;
	UnionFind uf(N);
	for(;Q--;){
		int q,u,v;
		cin>>q>>u>>v;
		if(q==1){
			u--,v--;
			uf.unite(u,v);
		}else{
			u--;
			cout<<uf.getk(u,v)<<endl;
		}
	}
}
