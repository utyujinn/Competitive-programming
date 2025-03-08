#include<iostream>
#include<vector>
using namespace std;
int N;
long K;
int A[2<<17];
int X[2<<17];
int ans[2<<17];
int dub[61][2<<17];

int main(){
	cin>>N>>K;
	for(int i=0;i<N;i++){
		cin>>X[i];X[i]--;
	}
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=0;i<N;i++)dub[0][i]=i;
	for(int i=0;i<N;i++)dub[1][i]=X[i];
	for(int i=2;i<61;i++){
		for(int j=0;j<N;j++){
			dub[i][j]=dub[i-1][dub[i-1][j]];
		}
	}
	int cnt=1;
	for(int i=0;i<N;i++)X[i]=i;
	while(K){
		if(K%2==1){
			for(int i=0;i<N;i++){
				X[i]=dub[cnt][X[i]];
			}
		}
		K/=2;
		cnt++;
	}
	for(int i=0;i<N;i++)cout<<A[X[i]]<<(i==N-1?"\n":" ");
}
