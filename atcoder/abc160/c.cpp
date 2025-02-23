#include<iostream>
using namespace std;
int A[2<<17];

int main(){
	int K,N;
	cin>>K>>N;
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	A[N]=A[0]+K;
	int ans=0;
	for(int i=0;i<N+1;i++){
		ans=max(A[i+1]-A[i],ans);
	}
	cout<<K-ans<<endl;
}
