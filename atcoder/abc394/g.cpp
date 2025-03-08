#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
using namespace std;
int H,W;
int F[500][500];
int Q;
int A[2<<17],B[2<<17],Y[2<<17],C[2<<17],D[2<<17],Z[2<<17];
vector<bool> M[500];
vector<int> mid[1<<20+1];

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

struct bill{
	int x,y;
	int h;
	bill(int _x,int _y,int _h):x(_x),y(_y),h(_h){}
};

int d[5]={0,1,0,-1};
UnionFind uf(250000);

void add(int x,int y){
	M[x][y]=true;
	for(int i=0;i<4;i++){
		int nx=x+d[i];
		int ny=y+d[i+1];
		if(nx>=0&&nx<H&&ny>=0&&ny<W)if(M[nx][ny]){
			uf.unite(x*500+y,nx*500+ny);
		}
	}
}

int main(){
	cin>>H>>W;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			cin>>F[i][j];
		}
	}
	cin>>Q;
	for(int i=0;i<Q;i++){
		cin>>A[i]>>B[i]>>Y[i]>>C[i]>>D[i]>>Z[i];
		A[i]--,B[i]--,C[i]--,D[i]--;
	}
	vector<bill> list;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			bill tmp={i,j,F[i][j]};
			list.push_back(tmp);
		}
	}
	sort(list.begin(),list.end(),[](bill a,bill b){
			return tie(a.h,b.x,b.y)>tie(b.h,a.x,a.y);
		});
	vector<int> ok(Q);
	vector<int> ng(Q);
	for(int i=0;i<Q;i++){
		ok[i]=1e6;
		ng[i]=-1;
		mid[(ok[i]+ng[i])/2].push_back(i);
	}
	for(int i=0;i<500;i++)M[i].assign(500,false);
	while(true){
		auto it=list.begin();
		for(int h=1<<20;h>=0;h--){
			while(it->h>=h&&it!=list.end()){
				add(it->x,it->y);
				it++;
			}
			for(auto id:mid[h]){
				if(uf.same(A[id]*500+B[id],C[id]*500+D[id])){
					ng[id]=h;
				}else{
					ok[id]=h;
				}
			}
		}
		for(int i=0;i<1<<20+1;i++){
			mid[i].clear();
		}
		bool flag=true;
		for(int i=0;i<Q;i++){
			mid[(ok[i]+ng[i])/2].push_back(i);
			if(ok[i]-ng[i]>1){
				flag=false;
			}
		}
		if(flag)break;
		for(int i=0;i<500;i++)M[i].assign(500,false);
		uf.clear();
	}
	for(int i=0;i<Q;i++){
		if(min(Y[i],Z[i])>ng[i]){
			cout<<Y[i]+Z[i]-ng[i]*2<<endl;
		}else{
			cout<<abs(Y[i]-Z[i])<<endl;
		}
	}
}
