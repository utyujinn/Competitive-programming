#include<iostream>
using namespace std;

int main(){
	int N,K;
	cin>>N>>K;
	string S;
	cin>>S;
	int cnt=0;
	int one=0,zero=0;
	for(int i=0;i<N;i++){
		if(cnt==K-1){
			if(S[i]=='1')one++;
			else zero++;
		}
		else{
			cout<<S[i];
		}
		if(S[i]=='1'&&S[i+1]=='0'){
			cnt++;
			if(cnt==K){
				for(int j=0;j<one;j++)cout<<1;
				for(int j=0;j<zero;j++)cout<<0;
			}
		}
	}
	if(cnt==K-1){
		for(int j=0;j<one;j++)cout<<1;
		for(int j=0;j<zero;j++)cout<<0;
	}

	cout<<endl;
}
