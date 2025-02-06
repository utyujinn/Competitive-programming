#include<iostream>
#include<vector>
using namespace std;
int a[100001];
int b[11];

void solve(){
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a+n);
	for(int i = 0; i < m; i++){
		cin >> b[i];
		b[i] = ~b[i];
	}
}

int main(){
	int t;
	cin >> t;
	for(;t--;)solve();
}
