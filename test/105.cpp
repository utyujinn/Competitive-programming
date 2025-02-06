#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int k,n;
	long l,r;
	cin >> n >> k >> l >> r;
	vector<long> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector w1(n/2+1, vector<long>(0));
	vector w2(n-n/2+1, vector<long>(0));
	for(int i = 0; i < 1<<(n/2); i++){
		long tmp = 0;
		for(int j = 0; j < n/2; j++){
		  if(i & (1<<j)){
				tmp += a[j];
			}
		}
		w1[__builtin_popcount(i)].push_back(tmp);
	}
	for(int i = 0; i < 1<<(n-n/2); i++){
		long tmp = 0;
		for(int j = 0; j < n-n/2; j++){
		  if(i & (1<<j)){
				tmp += a[j+n/2];
			}
		}
		w2[__builtin_popcount(i)].push_back(tmp);
	}

	for(int i = 0; i < n/2; i++){
		sort(w1[i].begin(), w1[i].end());
	}
	for(int i = 0; i < n-n/2; i++){
		sort(w2[i].begin(), w2[i].end());
	}
	long ans = 0;
	for(int i = 0; i <= n/2; i++){
		for(int j = 0; j <= n-n/2; j++){
			if(i+j==k){
				for(auto x: w1[i]){
					int left = lower_bound(w2[j].begin(), w2[j].end(), l-x) - w2[j].begin();
					int right = lower_bound(w2[j].begin(), w2[j].end(), r+1-x) - w2[j].begin();
					ans += right - left;
				}
			}
		}
	}
	cout << ans << endl;
}
