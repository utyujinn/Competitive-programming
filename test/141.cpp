#include<iostream>
#include<vector>
using namespace std;
int INF = ~0U>>1;

struct RMQ{
	int n;
	vector<int> a;
	vector<int> lazy;
	RMQ(int _n){
		int tmp=1;
		while(tmp<_n){
			tmp<<=1;
		}
		n = tmp;
		a.assign(n*2,INF);
		lazy.assign(n*2,INF);
	}

	void eval(int k){
		if(lazy[k] == INF) return;
		if(k < n){
			lazy[k*2] = lazy[k];
			lazy[k*2+1] = lazy[k];
		}
		a[k] = lazy[k];
		lazy[k] = INF;
	}

	int query(int s, int t, int k,int l, int r){
		eval(k);
		if(r<=s||t<=l){
			return INF;
		}else if(s <= l && r <= t){
			int vl = query(s,t,k*2,l,(l+r)/2);
			int vr = query(s,t,k*2+1,(l+r)/2,r);
			return min(vl,vr);
		}
	}

	int query(int a, int b){
		return query(a,b,1,1,n+1);
	}

	void update(int s, int t, int x, int k, int l, int r){
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

	void update(int s, int t, int x){
		update(s,t,x,1,1,n+1);
	}
};

int main(){
	int n,q;
	cin >> n >> q;
	RMQ rmq(n);
	int com,s,t,x;
	for(;q--;){
		cin >> com;
		if(com == 0){
			cin >> s >> t >> x;
			rmq.update(s,t,x);
		}else{
			cin >> s >> t;
			cout << rmq.query(s,t) << endl;
		}
	}
}
