#include<iostream>
using namespace std;

int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]!='.')cout<<s[i];
	}
	cout<<endl;
}
