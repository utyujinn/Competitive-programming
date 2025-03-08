#include<iostream>
using namespace std;

int main(){
	string S;cin>>S;
	int cnt=0;
	for(int i=0;i<S.size();i++){
		if(S[i]>='a'&&S[i]<='z')cnt++;
	}
	if(cnt>S.size()-cnt){
		for(int i=0;i<S.size();i++){
			if(S[i]>='A'&&S[i]<='Z')S[i]+='a'-'A';
		}
	}
	else{
		for(int i=0;i<S.size();i++){
			if(S[i]>='a'&&S[i]<='z')S[i]+='A'-'a';
		}
	}
	cout<<S<<endl;
}
