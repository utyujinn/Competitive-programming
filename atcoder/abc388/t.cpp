#include<iostream>
#include<vector>
using namespace std;

template <typename T>
struct BIT {
    int n;             
    vector<T> bit[2];  
    BIT(int n_) { init(n_); }
    void init(int n_) {
        n = n_ + 1;
        for (int p = 0; p < 2; p++) bit[p].assign(n, 0);
    }

    void add_sub(int p, int i, T x) {
        for (int idx = i; idx < n; idx += (idx & -idx)) {
            bit[p][idx] += x;
        }
    }
    void add(int l, int r, T x) { 
        add_sub(0, l, -x * (l - 1));
        add_sub(0, r, x * (r - 1));
        add_sub(1, l, x);
        add_sub(1, r, -x);
    }

    T sum_sub(int p, int i) {
        T s(0);
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            s += bit[p][idx];
        }
        return s;
    }
    T sum(int i) { return sum_sub(0, i) + sum_sub(1, i) * i; }
};

int main(){
	int n;
	cin >> n;
	vector<long> a(n+1);
	BIT<long> bt(n+1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] += bt.sum(i)-bt.sum(i-1);
		long give =  n - i;
		if(a[i] >= give){
			a[i] -= give;
		}else{
			give = a[i];
			a[i] = 0;
		}
		bt.add(i+1, i+give+1, 1);
	}
	for(int i = 1; i <= n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
