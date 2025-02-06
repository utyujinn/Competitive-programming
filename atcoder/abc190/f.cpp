#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

template <class T>
struct BIT {
  BIT(const int _n = 0) : n(_n), d(n){}
  BIT(const vector<T> &v) : d(v), n(v.size()){
    for(int i = 1; i <= n; i++){
      const int j = i + (i & -i);
      if(j <= n) d[j - 1] += d[i - 1];
    }
  }
  T sum(const int l, const int r) const{
    assert(0 <= l && l <= r && r <= n);
    return sum(r) - sum(l);
  }
  T sum(int i) const{
    T tot = 0;
    while(i > 0){
      tot += d[i - 1];
      i -= i & -i;
    }
    return tot;
  }
  void add(int i, const T &x){
    assert(0 <= i && i < n);
    i++;
    while(i <= n){
      d[i - 1] += x;
      i += i & -i;
    }
  }
  private:
  int n = 1;
  vector<T> d;
};

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	BIT<int> bit(n);
	long long sum = 0;
	for(int i = 0; i<n; i++){
		bit.add(a[i],1);
		sum += bit.sum(a[i]+1, n);
	}
	cout << sum << endl;
	for(int i = 0; i < n-1; i++){
		sum -= bit.sum(0,a[i]);
		sum += bit.sum(a[i]+1, n);
		cout << sum << endl;
	}

}
	
