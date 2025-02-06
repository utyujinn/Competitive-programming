#include<iostream>
#include<vector>
using namespace std;
int INF = ~0U>>1;

struct SegTree{
	int n;
	vector<int> a,lazy;
	SegTree(int _n){
		int tmp=1;
		while(tmp<_n){
			tmp<<=1;
		}
		n = tmp;
		a.assign(2*n,0);
		lazy.assign(2*n,0);
	}

	void eval(int k){
		if(lazy[k] == 0)return;
		if(k < n){
			lazy[k*2] += lazy[k];
			lazy[k*2+1] += lazy[k];
		}
		a[k] += lazy[k];
		lazy[k] = 0;
	}

	void add(int s, int t, int x, int k, int l, int r){
		eval(k);
		if(s <= l && r <= t){
			lazy[k] = x;
			eval(k);
		}
		else if(s < r && l < t){
			add(s,t,x,k*2,l,(l+r)/2);
			add(s,t,x,k*2+1,(l+r)/2,r);
			a[k] = min(a[k*2], a[k*2+1]);
		}
	}

	void add(int s, int t, int x){
		add(s,t,x,1,0,n);
	}

	int find(int s, int t, int k, int l, int r){
		eval(k);
		if(t <= l || r <= s){
			return INF;
		}else if(s <= l && r <= t){
			return a[k];
		}else{
			int vl = find(s,t,k*2,l,(l+r)/2);
			int vr = find(s,t,k*2+1,(l+r)/2,r);
			return min(vl,vr);
		}
	}

	int find(int s, int t){
		return find(s,t,1,0,n);
	}
};

int main(){
	int n,q;
	cin >> n >> q;
	SegTree seg(n);
	int c;
	int s,t,x;
	for(int i = 0; i < q; i++){
		cin >> c;
		if(c==0){
			cin >> s >> t >> x;
			seg.add(s,t+1,x);
		}
		else{
			cin >> s >> t;
			cout << seg.find(s,t+1) << endl;
		}
	}	
}
