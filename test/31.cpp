#include<iostream>
#include<vector>
#include<queue>

using namespace std;
//int dodd[6][2] = {{1,0},{1,1},{0,1},{-1,0},{0,-1},{1,-1}};
//int deven[6][2] = {{1,0},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1}};
int dodd[6][2] = {{0,1},{1,1},{1,0},{0,-1},{-1,0},{-1,1}};
int deven[6][2] = {{0,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0}};

int main(){
	int w,h;
	cin >> w >> h;
	vector<vector<int>> c(h+2, vector<int>(w+2));
	for(int i = 0; i < h; i++)for(int j = 0; j < w; j++)cin >> c[i+1][j+1];
	for(int i = 0; i < h+2; i++)c[i][0] = 0, c[i][w+1] = 0;
	for(int i = 0; i < w+2; i++)c[0][i] = 0, c[h+1][i] = 0;
	queue<pair<int, int>> Q;
	vector<vector<int>> isblack(h+2, vector<int>(w+2, 1));
	vector<vector<int>> seen(h+2, vector<int>(w+2, 0));
	Q.emplace(0,0);
	isblack[0][0] = 0;
	while(!Q.empty()){
		pair<int, int> v = Q.front();
		Q.pop();
		for(int i = 0; i < 6; i++){
			pair<int, int> d;
			if(v.first%2)d = {dodd[i][0], dodd[i][1]};
			else d = {deven[i][0], deven[i][1]};
			pair<int, int> nv = make_pair(v.first + d.first, v.second + d.second);
			if(nv.first >= 0 && nv.first < h+2 && nv.second >= 0 && nv.second < w+2){
				if(!seen[nv.first][nv.second]){
					seen[nv.first][nv.second] = 1;
					if(c[nv.first][nv.second] == 0){
						isblack[nv.first][nv.second] = 0;
						Q.push(nv);
					}
				}
			}
		}
	}

	long ans = 0;
	for(int i = 0; i < h+2; i++)for(int j = 0; j < w+2; j++){
		for(int k = 0; k < 6; k++){
			pair<int, int> d;
			if(i%2)d = {dodd[k][0], dodd[k][1]};
			else d = {deven[k][0], deven[k][1]};
			pair<int, int> nv = make_pair(i + d.first, j + d.second);
			if(nv.first >= 0 && nv.first < h+2 && nv.second >= 0 && nv.second < w+2){
				if(isblack[i][j] ^ isblack[nv.first][nv.second])ans++;
			}
		}
	}
	cout << ans/2 << endl;
}
