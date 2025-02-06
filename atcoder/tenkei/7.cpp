#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int q;
	cin >> q;
	for(int i = 0; i < q;i++){
		int b;
		cin >> b;
		int ok=n,ng = -1;
		while(ok-ng>1){
			int mid = (ok+ng)/2;
			if(a[mid] > b)ok = mid;
			else ng = mid;
		}
		if(ok > 0)
			cout << min(abs(a[ok]-b), abs(a[ng]-b)) << endl;
		else
			cout << abs(a[ok]-b) << endl;
	}
}
