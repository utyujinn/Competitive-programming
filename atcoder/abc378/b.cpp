#include<iostream>
using namespace std;
int q[100],r[100];
int N;

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>q[i]>>r[i];
	}
	int Q;
	cin>>Q;
	for(;Q--;){
		int t,d;
		cin>>t>>d;
		t--;
		cout<<((d-r[t]+q[t]-1)/q[t])*q[t]+r[t]<<endl;
	}
}
