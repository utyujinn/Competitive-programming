#include<iostream>
#include<vector>
using namespace std;
struct UnionFind{
	int N;
	vector<int> size, parent;
	UnionFind(int _n): N(_n),size(_n, 1),parent(_n, -1){}
	int root(int x){
		if(parent[x] == -1)return x;
		else return root(parent[x]);
	}
	bool same(int x,int y){
		return root(x) == root(y);
	}
	void unite(int x,int y){
		if(same(x,y))return;
		int rx = root(x), ry = root(y);
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
	void clear(){
		for(int i=0;i<N;i++){
			size[i]=1;
			parent[i]=-1;
		}
	}
};

int main(){
  int N,M;cin>>N>>M;
  UnionFind uf(N);
  int ans=0;
  for(int i=0;i<M;i++){
    int u,v;cin>>u>>v;
    u--,v--;
    if(uf.same(u,v)){
      ans++;
    }else{
      uf.unite(u,v);
    }
  }
  cout<<ans<<endl;
}
