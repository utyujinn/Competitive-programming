#include<iostream>
#include<vector>
using namespace std;
int N,M,Q;
int a[2<<17],b[2<<17];
int x[1<<17],y[1<<17];
int ok[1<<17],ng[1<<17];
vector<int> mid[2<<17];

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
	cin>>N>>M;
	for(int i=0;i<M;i++){
		cin>>a[i]>>b[i];
		a[i]--,b[i]--;
	}
	cin>>Q;
	for(int i=0;i<Q;i++){
		cin>>x[i]>>y[i];
		x[i]--,y[i]--;
	}
	for(int i=0;i<Q;i++){
		ok[i]=M+1;
		ng[i]=-1;
		mid[(ok[i]+ng[i])/2].push_back(i);
	}
	UnionFind uf(N);
	while(true){
		for(int m=0;m<=M;m++){
			for(int id:mid[m]){
				if(uf.same(x[id],y[id])){
					ok[id]=m;
				}else{
					ng[id]=m;
				}
			}
			if(m!=M)uf.unite(a[m],b[m]);
		}
		for(int m=0;m<=M;m++){
			mid[m].clear();
		}
		bool flag=true;
		for(int id=0;id<Q;id++){
			mid[(ok[id]+ng[id])/2].push_back(id);
			if(ok[id]-ng[id]>1)flag=false;
		}
		if(flag)break;
		uf.clear();
	}
	for(int i=0;i<Q;i++){
		if(ok[i]==M+1)cout<<-1<<endl;
		else cout<<ok[i]<<endl;
	}
}
