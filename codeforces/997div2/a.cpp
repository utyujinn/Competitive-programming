#include<iostream>
#include<vector>
using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	long ans = n*m*m;
	int x,y;
	cin >> x >> y;
	n--;
	long xsum = m, ysum = m;
	for(;n--;){
		cin >> x >> y;
		xsum += x;
		ysum += y;
	}
	cout << xsum * 2 + ysum * 2 << endl;
}

int main(){
	int t;
	cin >> t;
	for(;t--;){
		solve();
	}
}
