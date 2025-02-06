#include<iostream>
using namespace std;

int main(){
	int n,d;
	cin >> n >> d;
	string s;
	cin >> s;
	int ans = 0;
	for(int i = n-1; i >= 0; i--){
		if(s[i] == '@'){
			s[i] = '.';
			ans++;
		}
		if(ans == d)break;
	}
	cout << s << endl;
}
