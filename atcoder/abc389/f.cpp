#include<iostream>
#include<vector>
using namespace std;

struct BIT{
        int n;
        vector<int> bit[2];
        BIT(int _n) : n(_n+1){
                for(int p = 0; p < 2; p++){
                        bit[p].assign(n,0);
                }
        }
        void add_sub(int l, int i, int x){
                for(int idx = i; idx < n; idx += idx&(-idx)){
                        bit[l][idx] += x;
                }
        }
        void add(int i, int x){
                add_sub(0, i, x);
        }
        void add_range(int l, int r, int x){
                add_sub(0,l,-x*(l-1));
                add_sub(0,r+1,x*r);
                add_sub(1,l,x);
                add_sub(1,r+1,-x);
        }

        int sum_sub(int l, int i){
                int s = 0;
                for(int idx = i; idx > 0; idx -= idx&(-idx)){
                        s += bit[l][idx];
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
	int n;
	cin >> n;
	BIT bit(5e5+2);
	int l,r;
	for(int i = 0; i < n; i++){
		cin >> l >> r;
		int ok = r+1, ng = 0;
		while(ok-ng>1){
			int mid = (ok+ng)/2;
			if(bit.get(mid)+mid>r){
				ok = mid;
			}else{
				ng = mid;
			}
		}
		r = ng;
		ok = l+1, ng = 0;
		while(ok-ng>1){
			int mid = (ok+ng)/2;
			if(bit.get(mid)+mid>=l){
				ok = mid;
			}else{
				ng = mid;
			}
		}
		l = ok;
		bit.add_range(l, r, 1);
	}
	int q;
	cin >> q;
	int x;
	for(;q--;){
		cin >> x;
		cout << x+bit.get(x) << endl;
	}
}
