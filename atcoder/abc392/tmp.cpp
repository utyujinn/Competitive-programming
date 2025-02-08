#include<iostream>
#include<vector>
using namespace std;

struct UnionFind{
	int n;
	vector<long> size, parent;
	UnionFind(long _n): size(_n, 1), parent(_n, -1), n(_n){}
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
	vector<int> plist(){
		vector<int> ret;
		for(int i = 0; i < n; i++){
			if(parent[i] == -1)ret.push_back(i);
		}
		return ret;
	}
};

int main(){
	int N,M;
	cin>>N>>M;
	UnionFind uf(N);
	vector<int> a(M),b(M);
	for(int i=0;i<M;i++){
		cin>>a[i]>>b[i];
		a[i]--,b[i]--;
		uf.unite(a[i],b[i]);
	}
	int ans=uf.groups()-1;
	cout<<ans<<endl;
	auto pl = uf.plist();
	UnionFind uf2(N);
	int cnt=0;
	for(int i=0;i<M;i++){
		if(!uf2.same(a[i],b[i])){
			uf2.unite(a[i],b[i]);
		}
		else if(uf2.same(a[i],b[i])){
			for(int j=0;j<pl.size();j++){
				if(!uf.same(a[i],pl[j])){
					cout<<i+1<<" "<<b[i]+1<<" "<<pl[j]+1<<endl;
					uf.unite(a[i],pl[j]);
					uf2.unite(a[i],pl[j]);
					break;
				}
				else if(!uf.same(b[i],pl[j])){
					cout<<i+1<<" "<<b[i]+1<<" "<<pl[j]+1<<endl;
					uf.unite(b[i],pl[j]);
					uf2.unite(b[i],pl[j]);
					break;
				}
			}
			cnt++;
		}
		if(cnt==ans)break;
	}
}
