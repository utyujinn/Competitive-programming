#include<iostream>
using namespace std;

char flip(char a){
	if(a>='a'&&a<='z'){
		return a+'A'-'a';
	}
	else{
		return a+'a'-'A';
	}
}

int main(){
	string S;
	cin>>S;
	int Q;
	cin>>Q;
	for(;Q--;){
		long k;
		cin>>k;
		long a=S.size();
		while(a<k){
			a*=2;
		}
		int cnt=0;
		while(a>S.size()){
			if((k-1)%a>=a/2){
				cnt++;
			}
			a/=2;
		}
		if(cnt%2==1){
			cout<<flip(S[(k-1)%S.size()])<<" ";
		}
		else{
			cout<<S[(k-1)%S.size()]<<" ";
		}
	}
	cout<<endl;
}
