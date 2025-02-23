#include<vector>
#include<iostream>
using namespace std;
vector<vector<int>> d={{1,0},{0,1},{-1,0},{0,-1}};
int H,W,K;

int dfs(vector<vector<char>> &S,vector<vector<int>> &seen, int x, int y,int depth){
	if(depth==K)
		return 1;
	else{
		int ret=0;
		seen[x][y]=1;
		for(int i=0;i<4;i++){
			x+=d[i][0];
			y+=d[i][1];
			if(x>=0&&x<H&&y>=0&&y<W)if(S[x][y]=='.'&&!seen[x][y]){
				ret += dfs(S,seen,x,y,depth+1);
			}
			x-=d[i][0];
			y-=d[i][1];
		}
		seen[x][y]=0;
		return ret;
	}
}

int main(){
	cin>>H>>W>>K;
	vector<vector<char>> S(H,vector<char>(W));
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			cin>>S[i][j];
		}
	}
	int ans=0;
	vector<vector<int>> seen(H,vector<int>(W));
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(S[i][j]=='.'){
				seen[i][j]=1;
				ans+=dfs(S,seen,i,j,0);
				seen[i][j]=0;
			}
		}
	}
	cout<<ans<<endl;
}
