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
	long ans = 0;
	long index = n/2;
	for(int i = 0; i < n/2; i++){
		long ok = n; 
		long ng = -1;
		while(ok-ng>1){
			long mid = (ok+ng)/2;
			if(a[mid] >= a[i]*2) ok = mid;
			else ng = mid;
		}
		if(ok == n)break;
		if(index < ok){
			index = ok+1;
		}else{
			index++;
		}
		ans++;
		if(index == n)break;
	}
	cout << ans << endl;
}
