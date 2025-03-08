#include<iostream>
#include<set>
using namespace std;
int H,W,Y;
int cnt;
int h;
set<pair<int,int>> list[1<<17];
int A[1000][1000];
bool sank[1000][1000];
int d[5]={0,1,0,-1};

void dfs(int x,int y){
	for(int i=0;i<4;i++){
		int nx=x+d[i],ny=y+d[i+1];
		if(nx>=0&&ny>=0&&nx<H&&ny<W){
			if(A[nx][ny]<=h&&!sank[nx][ny]){
				sank[nx][ny]=true;
				cnt--;
				dfs(nx,ny);
			}
		}
	}
}

int main(){
	cin>>H>>W>>Y;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			cin>>A[i][j];
			list[A[i][j]].emplace(i,j);
			sank[i][j]=false;
		}
	}
	cnt=H*W;
	for(h=1;h<=Y;h++){
		for(auto[x,y]:list[h]){
			bool flag=false;
			for(int i=0;i<4;i++){
				int nx=x+d[i],ny=y+d[i+1];
				if(sank[nx][ny])flag=true;
			}
			if(!sank[x][y] && (flag || (x==0||x==H-1||y==0||y==W-1))){
				sank[x][y]=true;
				cnt--;
				dfs(x,y);
			}
		}
		cout<<cnt<<"\n";
	}
}
