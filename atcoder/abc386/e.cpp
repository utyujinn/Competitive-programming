#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	vector<long> a(n);
	long sum = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum ^= a[i];
	}
	long ans = 0;
	if(k<n-k){
		long tmp = 0;
		tmp ^= a[i];

		ans = max(tmp, ans);
	}
	else{

		ans = max(tmp, ans);
	}
	cout << ans << endl;
}
