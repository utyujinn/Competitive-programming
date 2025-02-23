#include<iostream>
#include<vector>
using namespace std;

struct UnionFind{
	int n;
	vector<long> size, parent,big,small;
	UnionFind(long _n): size(_n, 1), parent(_n, -1),big(_n),small(_n),n(_n){
		for(int i=0;i<_n;i++){
			big[i]=i;
			small[i]=i;
		}
	}
	int sz(int x){
		return size[root(x)];
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
		if(size[rx] > size[ry]){
			parent[ry] = rx;
			size[rx] += size[ry];
			big[rx]=max(big[rx],big[ry]);
			small[rx]=min(small[rx],small[ry]);
		}
		else{
			parent[rx] = ry;
			size[ry] += size[rx];
			big[ry]=max(big[rx],big[ry]);
			small[ry]=min(small[rx],small[ry]);
		}
		return;
	}
	int up(int x){
		return big[root(x)];
	}
	int down(int x){
		return small[root(x)];
	}
};

int main(){
	int N,Q;
	cin>>N>>Q;
	vector<int> cnt(N,1);
	vector<int> color(N);
	for(int i=0;i<N;i++)color[i]=i;
	UnionFind uf(N);
	for(;Q--;){
		int a,x,c;
		cin>>a;
		if(a==1){
			cin>>x>>c;
			x--,c--;
			int s = uf.sz(x);
			cnt[color[uf.root(x)]]-=s;
			cnt[c]+=s;
			int up=uf.up(x);
			int down=uf.down(x);
			color[uf.root(x)]=c;
			if(up+1<N)if(color[uf.root(up)]==color[uf.root(up+1)]){
				uf.unite(up,up+1);
			}
			if(down-1>=0)if(color[uf.root(down)]==color[uf.root(down-1)]){
				uf.unite(down,down-1);
			}
		}
		else{
			cin>>c;
			c--;
			cout<<cnt[c]<<endl;
		}
	}
}
