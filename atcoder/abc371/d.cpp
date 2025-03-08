#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int X[2<<17];
long P[2<<17];

int main(){
	int N;
	cin>>N;
	X[0]=1U<<31;
	for(int i=1;i<=N;i++){
		cin>>X[i];
	}
	for(int i=1;i<=N;i++){
		cin>>P[i];
		P[i]+=P[i-1];
	}
	int Q;
	cin>>Q;
	for(int i=0;i<Q;i++){
		int l,r;
		cin>>l>>r;
		int li=lower_bound(X,X+N+1,l)-X;
		int ri=lower_bound(X,X+N+1,r+1)-X;
		cout<<P[ri-1]-P[li-1]<<endl;
	}
}
