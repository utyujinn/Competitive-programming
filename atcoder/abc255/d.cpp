#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	long long n,q;
	cin >> n >> q;
	vector<long long> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<long long> sum(n);
	sum[0] = a[0];
	for(int i = 1; i < n; i++){
		sum[i] = sum[i-1] + a[i];
	}
	for(int i = 0; i<q; i++){
		long long tmp;
		cin >> tmp;
		long long ok = n;
		long long ng = -1;
		while((ok-ng) > 1){
			long long mid = (ok+ng)/2;
			if(a[mid]>=tmp)ok = mid;
			else ng = mid;
		}
		cout << 2*ok*tmp-n*tmp+sum[n-1]-2*((ng<0)?0:sum[ng]) << endl; 
	}
}
		


