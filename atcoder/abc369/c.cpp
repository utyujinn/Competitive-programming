#include<iostream>
using namespace std;
int A[2<<17];
int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	int con=1;
	int diff=A[1]-A[0];
	long ans=3;
	for(int i=2;i<N;i++){
		ans++;
		if(diff==A[i]-A[i-1])con++;
		else con=1;
		ans+=con;
		diff=A[i]-A[i-1];
	}
	if(N==1)cout<<1<<endl;
	else cout<<ans<<endl;
}
