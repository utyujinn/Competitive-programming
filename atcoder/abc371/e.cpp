#include<iostream>
using namespace std;
int N;
int pa[2<<17];
int a;

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		pa[i]=-1;
	}
	long ans=0;
	for(int i=0;i<N;i++){
		cin>>a;
		a--;
		ans+=(long)(i-pa[a])*(N-i);
		pa[a]=i;
	}
	cout<<ans<<endl;
}
