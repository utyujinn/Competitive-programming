#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<long> a(n);
	for(int i =0; i < n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	long ans = 0;
	for(int i = 0; i < n; i++){
		long ok = n; 
		long ng = -1;
		while(ok-ng>1){
			long mid = (ok+ng)/2;
			if(a[mid] >= a[i]*2) ok = mid;
			else ng = mid;
		}
		ans += n-ok;
	}
	cout << ans << endl;
}
