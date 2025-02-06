#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;

struct UnionFind{
	vector<int> parent,size;
	UnionFind(int n): parent(n,-1), size(n,1){}
	int root(int x){
		if(parent[x] == -1) return x;
		else return root(parent[x]);
	}
	bool same(int x, int y){
		return root(x)==root(y);
	}
	void unite(int x, int y){
		if(!same(x,y)){
			int rx = root(x), ry = root(y);
			if(size[rx] > size[ry]){
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
	int s,t;
	double d;
};

bool comp_e(Edge &a, Edge &b){
	return a.d < b.d;
}

void solve(int n){
	vector<double> x(n),y(n),z(n),r(n);
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i] >> z[i] >> r[i];
	}
	vector<Edge> list(0);
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			double dist = hypot(hypot(x[i]-x[j], y[i]-y[j]), z[i]-z[j])-r[i]-r[j];
			dist = dist < 0 ? 0: dist;
			Edge edge = {i,j,dist};
			list.push_back(edge);
		}
	}
	UnionFind uf(n);
	double ans = 0;
	sort(list.begin(), list.end(), comp_e);
	for(int i = 0; i < n*(n-1)/2; i++){
		if(!uf.same(list[i].s, list[i].t)){
			ans += list[i].d;
			uf.unite(list[i].s, list[i].t);
		}
	}
	cout << fixed << setprecision(3) << ans << endl;
}

int main(){
	int n;
	cin >> n;
	while(n!=0){
		solve(n);
		cin >> n;
	}
}
