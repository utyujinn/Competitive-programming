#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	long n;
	cin >> n;
	vector<long> a(n),b(n);
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
		a[i]--,b[i]--;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	long ans = 0;
	for(int i = 0; i < n; i++){
		ans += abs(a[i] - a[n/2]) + abs(a[i] - b[i]) + abs(b[i] - b[n/2]);
	}

	cout << ans << endl;
}

