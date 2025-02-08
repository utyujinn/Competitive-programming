#include<iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	string S;
	cin>>S;
	int flag=1;
	if(N%2==0)flag=0;
	for(int i=0;i<N/2;i++){
		if(S[i]!='1')flag=0;
	}
	if(S[N/2]!='/')flag=0;
	for(int i=N/2+1;i<N;i++){
		if(S[i]!='2')flag=0;
	}
	cout<<(flag?"Yes":"No")<<endl;
}
