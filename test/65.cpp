#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct UnionFind{
	vector<int> size,parent;
	UnionFind(int n) : size(n,1), parent(n,-1){}
	int root(int x){
		if(parent[x]==-1)return x;
		else return root(parent[x]);
	}
	bool same(int x, int y){
		return root(x)==root(y);
	}
	void unite(int x, int y){
		if(!same(x,y)){
			int rx = root(x),ry = root(y);
			if(size[rx]>size[ry]){
				parent[ry] = rx;
				size[rx] += size[ry];
			}else{
				parent[rx] = ry;
				size[ry] += size[rx];
			}
		}
	}
};
struct Edge{
	int s,t,d;
};
bool comp_e(const Edge &a, const Edge &b){
	return a.d < b.d;
}

int main(){
	int n,m,k;
	cin >> n >> m >> k;
	int snum = n;
	UnionFind uf(n);
	vector<Edge> list(m);
	for(int i = 0; i < m; i++){
		int s,t,d;
		cin >> s >> t >> d;
		s--,t--;
		list[i] = {s,t,d};
	}
	sort(list.begin(), list.end(), comp_e);
	long ans = 0;
	for(int i = 0; i < m && snum > k; i++){
		if(!uf.same(list[i].s, list[i].t)){
			uf.unite(list[i].s, list[i].t);
			ans += list[i].d;
			snum--;
		}
	}
	cout << ans << endl;
}


