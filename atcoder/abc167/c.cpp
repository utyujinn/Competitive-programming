#include<iostream>
using namespace std;
int N,M,X;
int A[12][12];
int C[12];
int S[1<<6][12];
int SC[1<<6];
int B[1<<6][12];
int BC[1<<6];

int main(){
	cin>>N>>M>>X;
	for(int i=0;i<N;i++){
		cin>>C[i];
		for(int j=0;j<M;j++)cin>>A[i][j];
	}
	for(int i=0;i<(1<<(N/2));i++){
		for(int j=0;j<N/2;j++){
			if(i&(1<<j)){
				for(int k=0;k<M;k++){
					S[i][k]+=A[j][k];
				}
				SC[i]+=C[j];
			}
		}
	}
	for(int i=0;i<(1<<(N-N/2));i++){
		for(int j=0;j<(N-N/2);j++){
			if(i&(1<<j)){
				for(int k=0;k<M;k++){
					B[i][k]+=A[N/2+j][k];
				}
				BC[i]+=C[N/2+j];
			}
		}
	}
	int ans=~0U>>1;
	for(int i=0;i<(1<<(N/2));i++){
		for(int j=0;j<(1<<(N-N/2));j++){
			if(SC[i]+BC[j]<ans){
				bool flag=true;
				for(int k=0;k<M;k++){
					if(S[i][k]+B[j][k]<X)flag=false;
				}
				if(flag)ans=min(ans,SC[i]+BC[j]);
			}
		}
	}
	if(ans==~0U>>1)cout<<-1<<endl;
	else cout<<ans<<endl;
}
