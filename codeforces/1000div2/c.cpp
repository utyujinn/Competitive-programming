#include<iostream>
#include<vector>
using namespace std;

struct UnionFind{
	int n;
	vector<long> size, parent;
	UnionFind(long _n): n(_n),size(_n, 1), parent(_n, -1){}
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
	int t;
	cin >> t;
	for(;t--;){
		int n;
		cin >> n;
		vector<vector<int>> g(n);
		vector<int> a(n),b(n);
		for(int i = 0; i < n-1; i++){
			cin >> a[i] >> b[i];
			a[i]--,b[i]--;
		  g[a[i]].push_back(b[i]);
			g[b[i]].push_back(a[i]);
		}
		int max1 = 0;
		int mi1 = -1;
		for(int i = 0; i < n; i++){
			if(g[i].size() >= max1){
				max1 = g[i].size();
				mi1 = i;
			}
		}
		g[mi1].clear();
		for(int i = 0; i < n; i++){
			int j= 0;
			int mem=-1;
			for(auto c: g[i]){
				if(c == mi1){
					mem = j;
				}
				j++;
			}
			if(mem != -1)g[i].erase(g[i].begin()+mem);
		}
		int max2 = 0;
		int mi2 = -1;
		for(int i = 0; i < n; i++){
			if(g[i].size() >= max2 && i != mi1){
				max2 = g[i].size();
				mi2 = i;
			}
		}
		UnionFind uf(n);
		for(int i = 0; i < n; i++){
			if(a[i] != mi1 && a[i] != mi2 && b[i] != mi1 && b[i] != mi2){
				uf.unite(a[i],b[i]);
			}
		}
		cout << uf.groups()-2 << endl;
	}
}
