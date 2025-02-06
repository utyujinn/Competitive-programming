#include<iostream>
#include<vector>
using namespace std;

struct BIT{
	int n;
	vector<int> bit[2];
	BIT(int _n) : n(_n){
		for(int p = 0; p < 2; p++){
			bit[p].assign(n,0);
		}
	}

	void add_sub(int p, int i, int x){
		i++;
		for(int idx = i; idx <= n; idx += idx&(-idx)){
			bit[p][idx-1] += x;
		}
	}
	void add(int i, int x){
		add_sub(0, i, x);
	}
	void add_range(int l, int r, int x){
		add_sub(0,l,-x*(l-1));
		add_sub(0,r,x*(r-1));
		add_sub(1,l,x);
		add_sub(1,r,-x);
	}

	int sum_sub(int p, int i){
		int s = 0;
		i++;
		for(int idx = i; idx > 0; idx -= idx&(-idx)){
			s += bit[p][idx-1];
		}
		return s;
	}
	int sum(int i){
		return sum_sub(0,i) + i * sum_sub(1,i);
	}
	int get(int i){
		return sum(i)-sum(i-1);
	}
};

int main(){
	int n,q;
	cin >> n >> q; 
	BIT bt(n+1);
	for(int i = 0; i < q; i ++){
		int com;
		cin >> com; 
		if(com == 0){
			int s,t,x;
			cin >> s >> t >> x;
			bt.add_range(s,t+1,x);
		}
		else{
			int x;
			cin >> x;
			cout << bt.get(x) << endl;
		}
	}
}
