#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,M,Q;
int U[2<<17],V[2<<17];
long T[2<<17];
long G[400][400];
int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)G[i][j]=~0ULL>>2;
		G[i][i]=0;
	}
	for(int i=0;i<M;i++){
		cin>>U[i]>>V[i]>>T[i];
		U[i]--,V[i]--;
		G[U[i]][V[i]]=min(G[U[i]][V[i]],T[i]);
		G[V[i]][U[i]]=min(G[V[i]][U[i]],T[i]);
	}
	for(int k=0;k<N;k++){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
			}
		}
	}
	cin>>Q;
	for(;Q--;){
		int K;cin>>K;
		vector<int> B(K);
		vector<int> P(K);
		for(int i=0;i<K;i++){
			cin>>B[i];
			B[i]--;
			P[i]=i;
		}
		long ans=~0ULL>>1;
		do{
			for(int i=(1<<K)-1;i>=0;i--){
				long tmp=0;
				int prev=0;
				for(int j=0;j<K;j++){
					int s,t;
					if(i&1<<j){
						s=U[B[P[j]]],t=V[B[P[j]]];
					}
					else{
						s=V[B[P[j]]],t=U[B[P[j]]];
					}
					tmp+=G[prev][s]+T[B[P[j]]];
					prev=t;
				}
				tmp+=G[prev][N-1];
				ans=min(tmp,ans);
			}
		}while(next_permutation(P.begin(),P.end()));
		cout<<ans<<endl;
	}
}
