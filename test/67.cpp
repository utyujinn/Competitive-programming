#include<iostream>
#include<vector>
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

struct XY{
	int index,x,y;
};

bool comp_x(XY &a, XY &b){
	return a.x<b.x;
}

bool comp_y(XY &a, XY &b){
	return a.y<b.y;
}

struct Edge{
	int s,t,d;
};

bool comp_e(Edge &a, Edge &b){
	return a.d < b.d;
}

int main(){
	int n;
	cin >> n;
	vector<XY> xy(n);
	for(int i = 0; i < n; i++){
		int x,y;
		cin >> x >> y;
		xy[i] = {i,x,y};
	}
	sort(xy.begin(), xy.end(), comp_x);
	vector<Edge> list(0);
	for(int i = 1; i < n; i++){
		Edge tmp = {xy[i-1].index,xy[i].index,min(xy[i].x-xy[i-1].x, abs(xy[i].y-xy[i-1].y))};
		list.push_back(tmp);
	}
	sort(xy.begin(), xy.end(), comp_y);
	for(int i = 1; i < n; i++){
		Edge tmp = {xy[i-1].index,xy[i].index,min(xy[i].y-xy[i-1].y, abs(xy[i].x-xy[i-1].x))};
		list.push_back(tmp);
	}
	sort(list.begin(), list.end(), comp_e);
	UnionFind uf(n);
	long ans = 0;
	for(int i = 0; i < n*2-2; i++){
		if(!uf.same(list[i].s, list[i].t)){
			uf.unite(list[i].s, list[i].t);
			ans+=list[i].d;
		}
	}
	cout << ans << endl;
}
