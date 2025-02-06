#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,l,k;
	cin >> n >> l >> k;
	vector<int> a(n);
	vector<int> size(n+1);
	int prev = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		size[i] = a[i]-prev;
		prev = a[i];
	}
	size[n] = l-a[n-1];
	int ok = -1, ng = l+1;
	while(ng-ok>1){
		int mid = (ok+ng)/2;
		int tmp = 0;
		int cnt = 0;
		for(int i = 0; i < n+1; i++){
			tmp += size[i];
			if(tmp >= mid){
				tmp = 0;
				cnt++;
			}
		}
		if(cnt >= k+1){
			ok = mid;
		}
		else ng = mid;
	}
	cout << ok << endl;
}
