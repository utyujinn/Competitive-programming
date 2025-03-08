#include<iostream>
using namespace std;

int main(){
	string s,t;cin>>s>>t;
	bool flag=true;
	for(int i=0;i<s.size();i++){
		if(s[i]!=t[i])flag=false;
	}
	if(flag)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
