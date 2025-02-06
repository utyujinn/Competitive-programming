#include<iostream>
#include<vector>
using namespace std;

struct UnionFind{
	vector<int> size,parent;
	UnionFind(int n): size(n,1), parent(n,-1){}
	int root(int x){
		if(parent[x] == -1)return x;
		else return root(parent[x]);
	}
	bool same(int x, int y){
		return root(x)==root(y);
	}
	void unite(int x, int y){
		if(same(x,y))return;
		int rx = root(x),ry = root(y);
		if(size[rx] > size[ry]){
			parent[ry] = rx;
			size[rx]+=size[ry];
		}
		else {
			parent[rx] = ry;
			size[ry]+=size[rx];
		}
	}
};

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> a(m),b(m);
	for(int i = 0; i < m; i++){
		cin >> a[i] >> b[i];
		a[i]--;
		b[i]--;
	}
	int ans = 0;
	for(int i = 0; i < m; i++){
		UnionFind uf(n);
		for(int j = 0; j < m; j++){
			if(i == j)continue;
			uf.unite(a[j],b[j]);
		}
		if(!uf.same(a[i],b[i]))ans++;
	}
	cout << ans << endl;
}
