#include<iostream>
#include<vector>
using namespace std;

struct BIT{
	int N;
	vector<long> tree;
	BIT(int _N):N(_N),tree(_N,0){
	}
	void add(int idx,int &x){
		idx++;
		for(;idx<=N;idx+=idx&(-idx)){
			tree[idx-1]+=x;
		}
	}
	long get_sum(int idx){
		long ret=0;
		idx++;
		for(;idx>0;idx-=idx&(-idx)){
			ret+=tree[idx-1];
		}
		return ret;
	}
	long get_range(int l,int r){
		return get_sum(r-1)-get_sum(l-1);
	}
};

int main(){
	int N,Q;
	cin>>N>>Q;
	BIT bit(N);
	for(int i=0;i<N;i++){
		int a;cin>>a;
		bit.add(i,a);
	}
	for(;Q--;){
		int q;cin>>q;
		if(q==0){
			int p,x;cin>>p>>x;
			bit.add(p,x);
		}
		else{
			int l,r;cin>>l>>r;
			cout<<bit.get_range(l,r)<<"\n";
		}
	}
}
