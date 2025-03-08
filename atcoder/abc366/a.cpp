#include<iostream>
using namespace std;

int main(){
	int N,T,A;cin>>N>>T>>A;
	int R=N-T-A;
	if(T+R<A||A+R<T)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
