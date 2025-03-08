#include<iostream>
#include<algorithm>
using namespace std;
int N,Q;
int dp[3001][3000];

pair<int,int> gor(int from,int to,int another,int cost){
	int n;
	if(from>to)to+=N;
	if(another<from)another+=N;
	if(another>from&&another<=to){
		n=to+1;
		cost+=n-another+to-from;
	}else{
		n=another;
		cost+=to-from;
	}
	n%=N;
	return make_pair(n,cost);
}

pair<int,int> gol(int from,int to,int another,int cost){
	from+=N,to+=N,another+=N;
	int n;
	if(from<to)to-=N;
	if(another>from)another-=N;
	if(another<from&&another>=to){
		n=to-1;
		cost+=from-to+another-n;
	}else{
		n=another;
		cost+=from-to;
	}
	n%=N;
	return make_pair(n,cost);
}

void print(){
	for(int i=0;i<=Q;i++)for(int j=0;j<N;j++){
		cout<<dp[i][j]<<(j==N-1?"\n":" ");
	}
}

int main(){
	cin>>N>>Q;
	for(int i=0;i<=Q;i++)for(int j=0;j<N;j++)dp[i][j]=~0U>>1;
	dp[0][1]=0;
	char prev='L';
	int pt=0;
	for(int i=0;i<Q;i++){
		char H;
		int T;
		cin>>H>>T;
		T--;
		if(prev==H){
			for(int j=0;j<N;j++){
				if(dp[i][j]!=~0U>>1){
					{auto[n,cost]=gor(pt,T,j,dp[i][j]);
					dp[i+1][n]=min(dp[i+1][n],cost);}
					{auto[n,cost]=gol(pt,T,j,dp[i][j]);
					dp[i+1][n]=min(dp[i+1][n],cost);}
				}
			}
		}
		else{
			for(int j=0;j<N;j++){
				if(dp[i][j]!=~0U>>1){
					{auto[n,cost]=gor(j,T,pt,dp[i][j]);
					dp[i+1][n]=min(dp[i+1][n],cost);}
					{auto[n,cost]=gol(j,T,pt,dp[i][j]);
					dp[i+1][n]=min(dp[i+1][n],cost);}
				}
			}
		}
		pt=T;
		prev=H;
	}
	int ans=~0U>>1;
	for(int i=0;i<N;i++){
		ans=min(ans,dp[Q][i]);
	}
	cout<<ans<<endl;
}
