#include<iostream>
#include<vector>
using namespace std;

struct BIT{
	int n;
	vector<int> bit;
	BIT(int _n) : n(_n+1),bit(n,0){}
	void add(int i, int x){
		for(int idx = i; idx < n; idx += idx&(-idx)){
			bit[idx] += x;
		}
	}
	int sum(int i){
		int s = 0;
		for(int idx = i; idx > 0; idx -= idx&(-idx)){
			s += bit[idx];
		}
		return s;
	}
	void list(){
		for(int i = 0; i < n; i++){
			cout << bit[i] << " ";
		}
		cout << endl;
	}
};

int main(){
	int n,q;
	cin >> n >> q; 
	BIT bt(n);
	for(int i = 0; i < q; i ++){
		int com, x,y;
		cin >> com >> x >> y;
		if(com == 0){
			bt.add(x,y);
		}
		else{
			cout << bt.sum(y) - bt.sum(x-1) << endl;
		}
		//bt.list();
	}
}
