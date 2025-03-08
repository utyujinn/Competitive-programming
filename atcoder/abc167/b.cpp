#include<iostream>
using namespace std;

int main(){
	long A,B,C,K;
	cin>>A>>B>>C>>K;
	long ans=0;
	if(K<=A)cout<<K<<endl;
	else if(K<=A+B)cout<<A<<endl;
	else cout<<A-(K-A-B)<<endl;
}
