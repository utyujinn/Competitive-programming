#include<iostream>
#include<queue>
using namespace std;
int H,W,D;
string S[1000];
int ans;
int d[5]={0,1,0,-1};
bool seen[1000][1000];

struct cur{
	int x,y,depth;
};

int main(){
	cin>>H>>W>>D;
	for(int i=0;i<H;i++)cin>>S[i];
	queue<cur> q;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(S[i][j]=='H'){
				seen[i][j]=true;
				cur tmp={i,j,0};
				q.push(tmp);
			}
		}
	}
	int ans=0;
	while(!q.empty()){
		ans++;
		auto a=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int nx=a.x+d[i],ny=a.y+d[i+1];
			if(nx>=0&&nx<H&&ny>=0&&ny<W&&a.depth<D)if(S[nx][ny]=='.'&&!seen[nx][ny]){
				seen[nx][ny]=true;
				cur tmp={nx,ny,a.depth+1};
				q.push(tmp);
			}
		}
	}
	cout<<ans<<endl;
}
