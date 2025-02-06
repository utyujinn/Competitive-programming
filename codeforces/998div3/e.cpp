#include<iostream>
#include<vector>
#include<set>
using namespace std;

struct UnionFind{
	vector<long> size, parent;
	long n;
	UnionFind(long _n): n(_n), size(_n, 1), parent(_n, -1){}
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
			if(parent[i] == -1){
				ret++;
			}
		}
		return ret;
	}
};

int main(){
	int t;
	cin >> t;
	for(;t--;){
		int n,m1,m2;
		cin >> n >> m1 >> m2;
		long ans = 0;
		UnionFind f(n),g(n);
		vector<pair<int,int>> list(m1);
		for(int i = 0; i < m1; i++){
			cin >> list[i].first >> list[i].second;
			list[i].first--;
			list[i].second--;
		}
		for(int i = 0; i < m2; i++){
			int u,v;
			cin >> u >> v;
			u--,v--;
			g.unite(u,v);
		}
		for(auto a: list){
			if(!g.same(a.first, a.second)){
				ans++;
			}else{
				f.unite(a.first, a.second);
			}
		}
		ans += f.groups() - g.groups();
		cout << ans << endl;
	}
}
