#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<typename T>
struct BIT{
	int n;
	vector<T> bit[2];
	BIT(int _n): n(_n+1){
		bit[0].assign(n,0);
		bit[1].assign(n,0);
	}

	void add_sub(int p, int i, T x){
		for(int idx = i; idx < n; idx += idx & -idx){
			bit[p][idx] += x;
		}
	}

	void add_range(int l, int r, T x){
		add_sub(0,l,-x*(l-1));
		add_sub(0,r+1,x*r);
		add_sub(1,l,x);
		add_sub(1,r+1,-x);
	}

	void add(int i, T x){
		add_sub(0, i, x);
	}

	T sum_sub(int p, T i){
		T sum = 0;
		for(int idx = i; idx > 0; idx -= idx & -idx){
			sum += bit[p][idx];
		}
		return sum;
	}

	T sum(int i){
		return sum_sub(0,i)+ i * sum_sub(1,i);
	}

	T get(int i){
		return sum(i)-sum(i-1);
	}
};

int main(){
	int n;
	long ans = 0;
	cin >> n;
	vector<int> a(n);
	BIT<int> bit(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<int> com = a;
	sort(com.begin(), com.end());
	for(int i = 0; i < n; i++){
		a[i] = lower_bound(com.begin(), com.end(), a[i]) - com.begin() + 1;
	}
	for(int i = 0; i < n; i++){
		ans += i-bit.sum(a[i]);
		bit.add(a[i],1);
	}
	cout << ans << endl;
}
