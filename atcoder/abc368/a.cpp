#include<iostream>
using namespace std;
int A[100];

int main(){
	int N,K;
	cin>>N>>K;
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=N-K;i<N;i++){
		cout<<A[i]<<" ";
	}
	for(int i=0;i<N-K;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}
