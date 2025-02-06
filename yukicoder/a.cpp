#include<iostream>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	string s;
	int r;
	int ans = 0;
	for(int i = 0; i < n; i++){
		cin >> s >> r;
		int flag = 0;
		for(int i = 0; i < 4; i++){
			if(s[i] == 'x')flag = 1;
		}
		if(flag && r >= 1200)ans++;
	}
	cout << ans << endl;
}
