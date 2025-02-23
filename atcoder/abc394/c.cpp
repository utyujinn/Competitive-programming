#include<iostream>
using namespace std;

int main(){
	string s;
	cin>>s;
	int idx=-1;
	for(int i=0;i<s.size();i++){
		if(idx==-1&&s[i]=='W'){
			idx=i;
		}
		if(idx!=-1&&s[i]!='W'&&s[i]!='A'){
			idx=-1;
		}
		if(idx!=-1&&s[i]=='A'){
			for(int j=idx+1;j<=i;j++){
				s[j]='C';
			}
			s[idx]='A';
			idx=-1;
		}
	}
	cout<<s<<endl;
}
