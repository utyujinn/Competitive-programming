#include<iostream>
using namespace std;

int main(){
	int N;cin>>N;
	int ans=0;
	for(;N--;){
		string S;
		cin>>S;
		if(S[0]=='T')ans++;
	}
	cout<<ans<<endl;
}
