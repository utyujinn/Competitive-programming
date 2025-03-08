#include<iostream>
using namespace std;
int A[100];
int main(){
	int N;cin>>N;
	bool flag=true;
	for(int i=0;i<N;i++){
		cin>>A[i];
		if(i>=1)if(A[i-1]>=A[i])flag=false;
	}
	if(flag)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
