#include<iostream>
using namespace std;
int N,M;
string S[50],T[50];

int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++)cin>>S[i];
	for(int i=0;i<M;i++)cin>>T[i];
	for(int a=0;a<=N-M;a++)for(int b=0;b<=N-M;b++){
		bool ok=true;
		for(int i=0;i<M;i++)for(int j=0;j<M;j++)if(S[a+i][b+j]!=T[i][j])ok=false;
		if(ok)cout<<a+1<<" "<<b+1<<endl;
	}
}
