#include<iostream>
#include<algorithm>
using namespace std;
int N,K;
int A[2<<17];

int main(){
	cin>>N>>K;
	for(int i=0;i<N;i++)cin>>A[i];
	sort(A,A+N);
	int ans=~0U>>1;
	for(int i=0;i<=K;i++){
		ans=min(ans,A[i+N-K-1]-A[i]);
	}
	cout<<ans<<endl;
}
