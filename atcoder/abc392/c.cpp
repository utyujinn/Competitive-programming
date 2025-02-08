#include<iostream>
#include<vector>
using namespace std;

int main(){
	int N;
	cin>>N;
	vector<int> P(N),Q(N),IP(N),IQ(N),A(N);
	for(int i=0;i<N;i++){
		cin>>P[i];
		P[i]--;
		IP[P[i]]=i;
	}
	for(int i=0;i<N;i++){
		cin>>Q[i];
		Q[i]--;
		IQ[Q[i]]=i;
	}
	for(int i=0;i<N;i++){
		A[i]=Q[P[IQ[i]]];
		cout<<A[i]+1<<" ";
	}
	cout<< endl;
}
