#include<iostream>
#include<vector>
using namespace std;

int main(){
	int k;
	string s,t;
	cin >> k >> s >> t;
	if(s.size() == t.size()){
		int diff = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] != t[i]){
				diff++;
			}
		}
		if(diff <= 1)cout << "Yes" << endl;
		else cout << "No" << endl;
	}else if(s.size() == t.size()+1){
		int j = 0;
		for(int i=0; i < t.size(); i++){
			if(s[i+j] != t[i]){
				j++;
				i--;
			}
			if(j==2){
				cout << "No" << endl;
				return 0;
			}
		}
		cout << "Yes" << endl;
	}else if(s.size() + 1 == t.size()){
		int j = 0;
		for(int i=0; i < s.size(); i++){
			if(s[i] != t[i+j]){
				j++;
				i--;
			}
			if(j==2){
				cout << "No" << endl;
				return 0;
			}
		}
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
}
