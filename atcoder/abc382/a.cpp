#include<iostream>
using namespace std;

int main(){
	int n,d;
	cin >> n >> d;
	string s;
	cin >> s;
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '.')ans++;
	}
	cout << ans+d << endl;
}
