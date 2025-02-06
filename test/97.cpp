#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
	long n,m;
	cin >> n >> m;
	vector<long> a(n);
	set<long> list;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i]/=2;
	}
	long ans = 0;
	for(int i = m; i >= 1; i--){
		for(int j = n-1; j >= 0; j--){
			if(!(i%a[j] == 0 && (i/a[j])%2 == 1)){
				break;
			}
			if(j == 0)ans++;
		}
	}
	cout << ans << endl;
}
