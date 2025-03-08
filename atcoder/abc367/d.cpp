#include<iostream>
using namespace std;
int list[1<<20];
long A[2<<17];
long S[2<<17];

int main(){
	int N,M;
	cin>>N>>M;
	long ans=0;
	cin>>A[0];
	list[0]++;
	S[0]=A[0];
	list[S[0]%M]++;
	//ans+=list[S[0]%M];
	for(int i=1;i<N;i++){
		if(i!=N-1){
		cin>>A[i];
		S[i]=A[i]+S[i-1];
		//ans+=list[S[i]%M];
		list[S[i]%M]++;
		}
		else{
		list[0]--;
		cin>>A[i];
		S[i]=A[i]+S[i-1];
		ans+=list[S[i]%M];
		list[S[i]%M]++;
		}
	}
	list[S[0]%M]--;
	S[0]=A[0]+S[N-1];
	ans+=list[S[0]%M];
	list[S[0]%M]++;
	for(int i=1;i<N-1;i++){
		list[S[i]%M]--;
		S[i]=A[i]+S[i-1];
		ans+=list[S[i]%M];
		list[S[i]%M]++;
	}
	cout<<ans<<endl;
}
