#include<iostream>
using namespace std;
long x[3],y[3];
long len[3];

int main(){
	for(int i=0;i<3;i++)cin>>x[i]>>y[i];
	for(int i=0;i<3;i++){
		len[i]=(x[(i+1)%3]-x[i])*(x[(i+1)%3]-x[i])+(y[(i+1)%3]-y[i])*(y[(i+1)%3]-y[i]);
	}
	for(int i=0;i<3;i++){
		if(len[i]==len[(i+1)%3]+len[(i+2)%3]){
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
}
