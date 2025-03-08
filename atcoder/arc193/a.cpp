#include<iostream>
#include<vector>
using namespace std;
long N,Q;
long W[2<<17];
long L[2<<17],R[2<<17];

long INF = ~0LLU>>1;
struct RMQ{
	long n;
	vector<long> a;
	vector<long> lazy;
	RMQ(long _n){
		long tmp=1;
		while(tmp<_n){
			tmp<<=1;
		}
		n = tmp;
		a.assign(n*2,INF);
		lazy.assign(n*2,INF);
	}

	void eval(long k){
		if(lazy[k] == INF) return;
		if(k < n){
			lazy[k*2] = min(lazy[k],lazy[k*2]);
			lazy[k*2+1] = min(lazy[k],lazy[k*2+1]);
		}
		a[k] = min(a[k],lazy[k]);
		lazy[k] = INF;
	}

	long query(long s, long t, long k,long l, long r){
		eval(k);
		if(r<=s||t<=l){
			return INF;
		}else if(s <= l && r <= t){
			return a[k];
		}else {
			long vl = query(s,t,k*2,l,(l+r)/2);
			long vr = query(s,t,k*2+1,(l+r)/2,r);
			return min(vl,vr);
		}
	}

	long query(long a, long b){
		return query(a,b,1,0,n);
	}

	void update(long s, long t, long x, long k, long l, long r){
		eval(k);
		if(s <= l && r <= t){
			lazy[k] = x;
			eval(k);
		}else if(s < r && l < t){
			update(s,t,x,k*2,l,(l+r)/2);
			update(s,t,x,k*2+1,(l+r)/2,r);
			a[k] = min(a[k*2], a[k*2+1]);
		}
	}

	void update(long s, long t, long x){
		update(s,t,x,1,0,n);
	}
};

int main(){
	cin>>N;
	RMQ Rs(2*N),Ls(2*N);
	for(long i=0;i<N;i++)cin>>W[i];
	for(long i=0;i<N;i++){
		cin>>L[i]>>R[i];
		L[i]--,R[i]--;
		Ls.update(R[i],R[i]+1,W[i]);
		Rs.update(L[i],L[i]+1,W[i]);
	}
	cin>>Q;
	for(long i=0;i<Q;i++){
		long s,t;
		cin>>s>>t;
		s--,t--;
		if(R[s]<L[t]||R[t]<L[s]){
			cout<<W[s]+W[t]<<endl;
		}else{
			long tmp=Ls.query(0,min(L[s],L[t]));
			tmp=min(tmp,Rs.query(max(R[s],R[t])+1,2*N));
			if(tmp==INF)cout<<-1<<endl;
			else cout<<W[s]+W[t]+tmp<<endl;
		}
	}
}
