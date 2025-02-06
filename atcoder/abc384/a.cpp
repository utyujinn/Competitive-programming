#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	char c1, c2;
	cin >> c1 >> c2;
	vector<char> s(n);
	for(int i = 0; i < n; i++){
		cin >> s[i];
		if(s[i] != c1)cout << c2;
		else cout << s[i];
	}
	cout << endl;
}
