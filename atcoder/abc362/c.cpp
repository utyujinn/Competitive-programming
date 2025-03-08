#include<iostream>
using namespace std;
int N;
int L[2<<17],R[2<<17];

int main(){
	cin>>N;
	long d=0,u=0;
	for(int i=0;i<N;i++){
		cin>>L[i]>>R[i];
		d+=L[i];
		u+=R[i];
	}
	if(d>0||u<0){
		cout<<"No"<<endl;
		return 0;
	}
	d=-d;
	cout<<"Yes"<<endl;
	for(int i=0;i<N;i++){
		if(d>R[i]-L[i]){
			cout<<R[i]<<" ";
			d-=R[i]-L[i];
		}else if(d){
			cout<<L[i]+d<<" ";
			d=0;
		}else{
			cout<<L[i]<<" ";
		}
	}
	cout<<endl;
}
