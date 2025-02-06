#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<char> s(n);
	for(int i = 0; i < n; i++)
		cin >> s[i];
	char prev = s[0];
	cout << s[0];
	for(int i = 1; i < n; i++){
		if(prev == 'n' && s[i] == 'a'){
			cout << "ya";
		}
		else{
			cout << s[i];
		}
		prev = s[i];
	}
	cout << endl;
}
		

