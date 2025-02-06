#include<iostream>
#include<vector>
using namespace std;

struct UnionFind {
	vector<int> parent;
	UnionFind(int n) : parent(n,-1){}
	int root(int x){
		if(parent[x] == -1)return x;
		else return root(parent[x]);
	}
	void unite(int x, int y){
		if(same(x,y)) return;
		parent[root(y)] = x;
	}
	bool same(int x, int y){
		return root(x)==root(y);
	}
};

int main(){
	int n,q;
	cin >> n >> q;
	UnionFind uf(n);
	for(;q--;){
		int com, x, y;
		cin >> com >> x >> y;
		if(com == 0){
			uf.unite(x,y);
		}
		else{
			if(uf.same(x,y))cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
}
