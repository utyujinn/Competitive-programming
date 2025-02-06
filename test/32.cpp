#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int d[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

int main(){
	while(true){
		int w,h;
		cin >> w >> h;
		if(w == 0 && h == 0)break;

		vector<vector<int>> vwall(h,vector<int>(w-1));
		vector<vector<int>> hwall(h-1, vector<int>(w));
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w-1; j++)
				cin >> vwall[i][j];
			for(int j = 0; j < w; j++){
				if(i == h-1)break;
				cin >> hwall[i][j];
			}
		}
		vector<vector<int>> dist(h,vector<int>(w,-1));

		queue<pair<int,int>> Q;
		Q.emplace(0,0);
		dist[0][0] = 1;
		while(!Q.empty()){
			pair<int,int> v = Q.front();
			Q.pop();
			for(int i = 0; i < 4; i++){
				int nvx = v.first+d[i][0];
				int nvy = v.second+d[i][1];
				if(nvx >= 0 && nvx < h && nvy >= 0 && nvy < w) 
				if(dist[nvx][nvy]==-1){
					if(i==0)if(vwall[v.first][v.second] == 0){
						dist[nvx][nvy] = dist[v.first][v.second] + 1;
						Q.emplace(nvx,nvy);
					}
					if(i==1)if(hwall[v.first][v.second] == 0){
						dist[nvx][nvy] = dist[v.first][v.second] + 1;
						Q.emplace(nvx,nvy);
					}
					if(i==2)if(vwall[v.first][v.second-1] == 0){
						dist[nvx][nvy] = dist[v.first][v.second] + 1;
						Q.emplace(nvx,nvy);
					}
					if(i==3)if(hwall[v.first-1][v.second] == 0){
						dist[nvx][nvy] = dist[v.first][v.second] + 1;
						Q.emplace(nvx,nvy);
					}
				}
			}
		}
		if(dist[h-1][w-1] == -1)cout << 0 << endl;
		else cout << dist[h-1][w-1] << endl;
	}
}
