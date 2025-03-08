#include<iostream>
using namespace std;
int A[100];

int main(){
	int N;cin>>N;
	for(int i=0;i<2*N;i++)cin>>A[i];
	int ans=0;
	for(int i=0;i<2*N-2;i++){
		if(A[i]==A[i+2])ans++;
	}
	cout<<ans<<endl;
}
