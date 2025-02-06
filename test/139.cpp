#include<iostream>
#include<vector>
using namespace std;
int INF = (1<<30)-1+(1<<30); 

struct RMQ{
	int n;
	vector<int> dat;
	RMQ(int _n){
		int a = 0;
		while(1<<a < _n){
			a++;
		}
		n = 1<<a;
		dat.assign(2*n-1, INF);
	}
	
	void update(int i, int x){
		i = i + n - 1;
		dat[i] = x;
		while(i > 0){
			i = (i-1)/2;
			dat[i] = min(dat[i*2+1], dat[i*2+2]);
		}
	}

	int query_sub(int a, int b, int k, int l, int r){
		if(r <= a || b <= l){
			return INF;
		}else if(a <= l && r <= b){
			return dat[k];
		}else {
			int vl = query_sub(a,b,k*2+1, l, (l+r)/2);
			int vr = query_sub(a,b,k*2+2, (l+r)/2, r);
			return min(vl,vr);
		}
	}

	int query(int a, int b){
		return query_sub(a,b,0,0,n);
	}

	void list(){
		for(int i = 0; i < n*2-1; i++){
			cout << dat[i] << " " ;
		}
		cout << endl;
	}
};

int main(){
	int n,q;
	cin >> n >> q;
	RMQ rmq(n);
	for(;q--;){
		int com, x, y;
		cin >> com >> x >> y;
		if(com== 0){
			rmq.update(x,y);
		}else{
			int ans = rmq.query(x,y+1);
			cout << ans << endl;
		}
	}
}
