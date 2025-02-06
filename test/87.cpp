#include<iostream>
#include<vector>
using namespace std;

struct UnionFind{
	vector<long> size, parent;
	UnionFind(long n): size(n, 1), parent(n, -1){}
	long root(long x){
		if(parent[x] == -1)return x;
		else return root(parent[x]);
	}
	bool same(long x, long y){
		return root(x) == root(y);
	}
	long unite(long x, long y){
		if(same(x,y))return 0;
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
		return connected;
	}
};

int main(){
	long n,m;
	cin >> n >> m;
	vector<long> a(m),b(m);
	for(int i = 0; i < m; i++){
		cin >> a[i] >> b[i];
		a[i]--;b[i]--;
	}
	UnionFind uf(n);
	vector<long> ans(m+1,n*(n-1)/2);
	for(int i=m-1; i >= 0; i--){
		ans[i] = ans[i+1] - uf.unite(a[i], b[i]);
	}
	for(int i = 1; i < m+1; i++){
		cout << ans[i] << endl;
	}
}
