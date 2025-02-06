#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int oddd[2][2] = {{1,0}, {-1,0}};
int evend[2][2] = {{0,1}, {0,-1}};

int main(){
	int h,w;
	cin >> h >> w;
	vector mp(h,vector<char>(w));
	int sx,sy;
	int gx,gy;
	for(int i = 0; i < h; i++){
		for(int j = 0;j < w;j++){
			cin >> mp[i][j];
			if(mp[i][j] == 'S'){
				sx=i;
				sy=j;
			}
			if(mp[i][j] == 'G'){
				gx=i;
				gy=j;
			}
		}
	}
	vector dist(h,vector<int>(w, 1<<30));
	dist[sx][sy] = 0;
	queue<pair<int,int>> q;
	q.push(make_pair(sx,sy));
	while(!q.empty()){
		auto c = q.front();
		q.pop();
		int cx = c.first;
		int cy = c.second;
		for(int i = 0; i < 2; i++){
			int nx,ny;
			if(dist[cx][cy]%2){
				nx = c.first + oddd[i][0];
				ny = c.second + oddd[i][1];
			}else{
				nx = c.first + evend[i][0];
				ny = c.second + evend[i][1];
			}
			if(nx >= 0 && nx < h && ny >= 0 && ny < w){
				if(dist[nx][ny] == 1<<30 && mp[nx][ny] != '#'){
					q.push(make_pair(nx,ny));
					dist[nx][ny] = dist[cx][cy]+1;
				}
				if(mp[nx][ny] == 'G')break;
			}
		}
	}

	vector dist2(h,vector<int>(w, 1<<30));
	dist2[sx][sy] = 0;
	q.push(make_pair(sx,sy));
	while(!q.empty()){
		auto c = q.front();
		q.pop();
		int cx = c.first;
		int cy = c.second;
		for(int i = 0; i < 2; i++){
			int nx,ny;
			if(!(dist2[cx][cy]%2)){
				nx = c.first + oddd[i][0];
				ny = c.second + oddd[i][1];
			}else{
				nx = c.first + evend[i][0];
				ny = c.second + evend[i][1];
			}
			if(nx >= 0 && nx < h && ny >= 0 && ny < w){
				if(dist2[nx][ny] == 1<<30 && mp[nx][ny] != '#'){
					q.push(make_pair(nx,ny));
					dist2[nx][ny] = dist2[cx][cy]+1;
				}
				if(mp[nx][ny] == 'G')break;
			}
		}
	}

	if(dist[gx][gy] == 1<<30 && dist2[gx][gy] == 1<<30)cout << -1 << endl;
	else cout << min(dist[gx][gy], dist2[gx][gy]) << endl;
}
