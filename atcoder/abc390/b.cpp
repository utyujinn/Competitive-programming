#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<long> a(n);
	int flag = 1;
	for(int i = 0; i < n;i++){
		cin >> a[i];
		if(!(i<=1)){
			if(a[i-1]*a[i-1] != a[i]*a[i-2])flag = 0;
		}
	}
	if(flag)cout << "Yes" << endl;
	else cout << "No" << endl;
}
