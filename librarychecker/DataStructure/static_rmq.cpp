#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
struct sRMQ{
	int N;
	vector<int> data,lazy;
	const int data_unit=~0U>>1;
	const int lazy_unit=~0U>>1;
	sRMQ(int _N):N(_N){
		data.assign(N*2,data_unit);
		lazy.assign(N*2,lazy_unit);
	}
	int data_f(int a,int b){
		return min(a,b);
	}
	int lazy_f(int a,int b){
		return b;
	}
	int operate(int x,int y){
		int s=(y==lazy_unit?x:y);
		return s;
	}
	void build(vector<int> &origin){
		for(int i=0;i<N;i++)data[i+N]=origin[i];
		for(int i=N-1;i>=1;i--)data[i]=data_f(data[i<<1],data[(i<<1)+1]);	
	}
	int _eval_at(int idx){
		return operate(data[idx],lazy[idx]);
	}
	void _propagate_at(int idx){
		data[idx]=_eval_at(idx);
		lazy[idx<<1]=lazy_f(lazy[idx<<1],lazy[idx]);
		lazy[(idx<<1)|1]=lazy_f(lazy[(idx<<1)|1],lazy[idx]);
		lazy[idx]=lazy_unit;
	}
	void _propagate_above(int idx){
		int cnt=0;
		int tmp=idx;
		while(tmp){
			cnt++;
			tmp>>=1;
		}
		for(int i=cnt-1;i>=0;i--){
			_propagate_at(idx>>i);
		}
	}
	void _recalc_above(int idx){
		while(idx>1){
			idx>>=1;
			data[idx]=data_f(data[idx<<1],data[(idx<<1)|1]);
		}
	}
	int get(int l,int r){
		l+=N,r+=N;
		_propagate_above(l/(l&-l));
		_propagate_above(r/(r&-r)-1);
		int xl=data_unit,xr=data_unit;
		while(l<r){
			if(l&1)xl=data_f(xl,data[l++]);
			if(r&1)xr=data_f(data[--r],xr);
			l>>=1,r>>=1;
		}
		return data_f(xl,xr);
	}
	void update(int l,int r,int x){
		l+=N,r+=N;
		int l0=l/(l&-l),r0=r/(r&-r)-1;
		_propagate_above(l0);
		_propagate_above(r0);
		while(l<r){
			if(l&1)l++,lazy[l]=lazy_f(lazy[l],x);
			if(r&1)r--,lazy[r]=lazy_f(lazy[r],x);
			l>>=1,r>>=1;
		}
		_recalc_above(l0);
		_recalc_above(r0);
	}
	void print(){
		for(int i=0;i<N*2;i++){
			cout<<data[i]<<" ";
		}cout<<endl;
		for(int i=0;i<N*2;i++){
			cout<<lazy[i]<<" ";
		}cout<<endl;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N,Q;cin>>N>>Q;
	vector<int> a(N);
	for(int i=0;i<N;i++)cin>>a[i];
	sRMQ rmq(N);
	rmq.build(a);
	for(;Q--;){
		int l,r;cin>>l>>r;
		cout<<rmq.get(l,r)<<"\n";
	}
}
