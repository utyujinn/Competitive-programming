#include<iostream>
using namespace std;
int N,X;
int U[2<<17],D[2<<17];

int main(){
	cin>>N>>X;
	for(int i=0;i<N;i++)cin>>U[i]>>D[i];
	long up=1<<31+1,down=-1;
	while(up-down>1){
		long mid=(up+down)/2;
		long da=0;ua=0;
		for(int i=0;i<N;i++){
			if(U[i]+D[i]<mid){
				up=mid;
				break;
			}
			else{
				int dela=U[i]+D[i]-mid;
				if(D[i]<=da){
					nd=0;
				}else{
					nd=D[i]-dela;
				}
				if(U[i]<=dela){
					nu=0;
				}else{
					nu=U[i]-dela;
				}
			}
			da=min(0,da-X),ua=max(ua+X,1<<31);


}
