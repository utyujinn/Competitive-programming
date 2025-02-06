#include<iostream>
#include<vector>
#include<limits>
using namespace std;

int main(){
	long n,x;
	cin >> n >> x;
	vector<int> a(n);
	vector<int> cnt(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		cnt[i] = a[i];
	}
	long ans = numeric_limits<long>::max();
	long sum;
	for(int k = 0; k < n; k++){
		sum = 0;
		for(int i = 0; i < n; i++){
			if(i-k<0){
				sum += min(cnt[i], a[n-(k-i)]);
				cnt[i] = min(cnt[i], a[n-(k-i)]);
			}else{
				sum += min(cnt[i], a[i-k]);
				cnt[i] = min(cnt[i], a[i-k]);
			}
		}
		sum += k*x;
		ans = min(sum,ans);
	}
	cout << ans << endl;
}
