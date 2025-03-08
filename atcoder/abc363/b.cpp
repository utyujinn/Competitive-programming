#include<iostream>
using namespace std;
int L[100];

int main(){
	int N,T,P;cin>>N>>T>>P;
	for(int i=0;i<N;i++)cin>>L[i];
	int ni=0;
	while(true){
		int cnt=0;
		for(int i=0;i<N;i++){
			if(L[i]>=T)cnt++;
			L[i]++;
		}
		if(cnt>=P)break;
		ni++;
	}
	cout<<ni<<endl;
}
