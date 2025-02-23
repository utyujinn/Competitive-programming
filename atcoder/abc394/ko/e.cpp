#include<iostream>
#include<vector>
using namespace std;

int N;
string G[100];
int D[100][100];
int main(){
	cin>>N;
	for(int i=0;i<N;i++)cin>>G[i];
	for(int i=0;i<N;i++)for(int j=0;j<N;j++){
		D[i][j]=1e9;
	}
	vector<pair<int,int> >Q;
	for(int i=0;i<N;i++){
		D[i][i]=0;
		Q.push_back(make_pair(i,i));
	}
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)if(i!=j&&G[i][j]!='-'){
		D[i][j]=1;
		Q.push_back(make_pair(i,j));
	}
	for(int k=0;k<Q.size();k++){
		auto[u,v]=Q[k];
		for(int w=0;w<N;w++)if(G[w][u]!='-'){
			for(int x=0;x<N;x++)if(G[v][x]==G[w][u]){
				int nd=D[u][v]+2;
				if(D[w][x]>nd){
					D[w][x]=nd;
					Q.push_back(make_pair(w,x));
				}
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			int ans=D[i][j];
			if(ans==1e9)ans=-1;
			cout<<ans<<(j+1==N?"\n":" ");
		}
	}
}
