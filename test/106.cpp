#include<iostream>
#include<vector>
using namespace std;

int main(){
	long n,W;
	cin >> n >> W;
	vector<long> v(n), w(n);
	for(int i = 0; i < n ;i++){
		cin >> v[i] >> w[i];
	}
	long n2 = n/2;
	vector<pair<long,long>> a,b;
	for(int i = 0; i < (1<<n2); i++){
		long tv=0,tw=0;
		for(int j = 0; j < n2; j++){
			if(i & (1<<j)){
				tv += v[j];
				tw += w[j];
			}
		}
		a.emplace_back(tv,tw);
	}
	for(int i = 0; i < (1<<(n2+n%2)); i++){
		long tv = 0, tw = 0;
		for(int j = 0; j < n2+(n%2); j++){
			if(i & (1<<j)){
				tv += v[n2+j];
				tw += w[n2+j];
			}
		}
		b.emplace_back(tv,tw);
	}
	long ans = 0;
	for(auto f: a){
		for(auto s: b){
			if(f.second+s.second<=W){
				ans = max(ans, f.first+s.first);
			}
		}
	}
	cout << ans << endl;
}
