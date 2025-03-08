#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int A[2<<17],B[2<<17];

int main(){
	int N,M;cin>>N>>M;
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=0;i<M;i++)cin>>B[i];
	sort(A,A+N);
	sort(B,B+M);
	long ans=0;
	int idx=0;
	for(int i=0;i<M;i++){
		if(idx==N){
			cout<<-1<<endl;
			return 0;
		}
		while(A[idx]<B[i]){
			idx++;
			if(idx==N){
				cout<<-1<<endl;
				return 0;
			}
		}
		ans+=A[idx];
		idx++;
	}
	cout<<ans<<endl;
}
