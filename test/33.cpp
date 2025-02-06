#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int d[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

int main(){
	int h,w;
	cin >> h >> w;
	int ans = 0;
	vector<vector<char>> s(h,vector<char>(w));
	for(int i = 0; i < h; i++)for(int j = 0; j < w; j++){
		cin >> s[i][j];
		if(s[i][j] == '.')ans++;
	}
	vector<vector<int>> dist(h,vector<int>(w,-1));
	queue<pair<int, int>> Q;
	Q.emplace(0,0);
	dist[0][0] = 1;
	while(!Q.empty()){
		pair<int, int> v = Q.front();
		Q.pop();
		for(int i = 0; i < 4; i++){
			int nvx = v.first + d[i][0];
			int nvy = v.second + d[i][1];
			if(nvx >= 0 && nvx < h && nvy >= 0 && nvy < w){
				if(s[nvx][nvy] == '.' && dist[nvx][nvy] == -1){
					dist[nvx][nvy] = dist[v.first][v.second] +1;
					Q.emplace(nvx,nvy);
				}
			}
		}
	}
	if(dist[h-1][w-1] == -1) cout << -1 << endl;
	else cout << ans - dist[h-1][w-1] << endl;
}
