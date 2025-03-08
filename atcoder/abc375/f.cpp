#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N,M,Q;
int A[5<<14],B[5<<14],C[5<<14];
vector<int> qu[2<<17];
bool dis[5<<14];
long G[300][300];

int main(){
	cin>>N>>M>>Q;
	for(int i=0;i<M;i++){
		cin>>A[i]>>B[i]>>C[i];
		A[i]--,B[i]--;
	}
	for(int i=0;i<Q;i++){
		int com;cin>>com;
		qu[i].push_back(com);
		if(com==1){
			int x;cin>>x;
			x--;
			qu[i].push_back(x);
			dis[x]=true;
		}
		else{
			int x,y;cin>>x>>y;
			x--,y--;
			qu[i].push_back(x);
			qu[i].push_back(y);
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			G[i][j]=~0ULL>>2;
		}
	}
	for(int i=0;i<M;i++){
		if(!dis[i]){
			G[A[i]][B[i]]=C[i];
			G[B[i]][A[i]]=C[i];
		}
	}
	for(int k=0;k<N;k++){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
			}
		}
	}
	vector<long> ans;
	for(int i=Q-1;i>=0;i--){
		if(qu[i][0]==1){
			int x=qu[i][1];
			G[A[x]][B[x]]=min(G[A[x]][B[x]],(long)C[x]);
			G[B[x]][A[x]]=min(G[B[x]][A[x]],(long)C[x]);
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					G[i][j]=min(G[i][j],G[i][A[x]]+G[A[x]][j]);
				}
			}
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					G[i][j]=min(G[i][j],G[i][B[x]]+G[B[x]][j]);
				}
			}
		}
		else{
			int u=qu[i][1],v=qu[i][2];
			if(G[u][v]==~0ULL>>2)ans.push_back(-1);
			else ans.push_back(G[u][v]);
		}
	}
	for(auto it=ans.rbegin();it!=ans.rend();it++){
		cout<<*it<<endl;
	}
}
