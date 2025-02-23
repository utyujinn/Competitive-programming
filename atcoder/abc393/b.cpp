#include<iostream>
using namespace std;

int main(){
	string s;
	cin>>s;
	int ans=0;
	for(int w=1;w<1+s.size()/2;w++){
		for(int i=0;i+2*w<s.size();i++){
			if(s[i]=='A'&&s[i+w]=='B'&&s[i+2*w]=='C')ans++;
		}
	}
	cout<<ans<<endl;
}
