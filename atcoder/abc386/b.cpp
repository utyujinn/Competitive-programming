#include<iostream>
#include<vector>
using namespace std;

int main(){
	string s;
	cin >> s;
	int aa = 0, ans = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '0')aa++;
		else aa = 0;
		if(aa%2 == 0 && aa != 0)ans--;
		ans++;
	}
	cout << ans << endl;
}
