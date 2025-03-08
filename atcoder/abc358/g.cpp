#include<iostream>
#include<queue>
using namespace std;
int H,W,K;
int x,y;
int A[50][50];
long M[50][50];
int d[5]={0,1,0,-1};
struct state{
	int x,y;
	long cnt;
	int zan;
};
int main(){
	cin>>H>>W>>K;
	cin>>x>>y;
	x--,y--;
	for(int i=0;i<H;i++)for(int j=0;j<W;j++)cin>>A[i][j];
	long ans=0;
	queue<state> q;
	state f={x,y,0,K};
	M[x][y]=A[x][y]*K;
	q.push(f);
	while(!q.empty()){
		auto[x,y,cnt,zan]=q.front();q.pop();
		if(zan==0||K-zan>=1000)continue;
		if(cnt+(long)zan*A[x][y]<M[x][y])continue;
		for(int i=0;i<4;i++){
			int nx=x+d[i],ny=y+d[i+1];
			if(nx>=0&&nx<H&&ny>=0&&ny<W){
				if((long)A[nx][ny]*zan+cnt>M[nx][ny]){
					M[nx][ny]=(long)A[nx][ny]*zan+cnt;
					ans=max(ans,M[nx][ny]);
				}
				//state tmp={nx,ny,cnt+A[nx][ny],zan-1};
				//q.push(tmp);
			}
		}
	}
	for(int i=0;i<H;i++)for(int j=0;j<W;j++)cout<<M[i][j]<<(j==W-1?"\n":" ");
	cout<<ans<<endl;
}
