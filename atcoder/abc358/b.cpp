#include<iostream>
using namespace std;
int T[100];

int main(){
	int N,A;
	cin>>N>>A;
	int cnt=0;
	for(int i=0;i<N;i++){
		cin>>T[i];
		if(T[i]>cnt){
			cnt=T[i];
			cnt+=A;
		}else{
			cnt+=A;
		}
		cout<<cnt<<endl;
	}
}
