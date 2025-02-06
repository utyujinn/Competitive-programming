#include<iostream>
#include<algorithm>
using namespace std;
int ice[90][90];
bool seen[90][90] = {false};
int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int m,n;

long dfs(int x, int y){
	seen[x][y] = true;
	long long cnt = 1;
	long long tmp = 0;
	for(int i = 0; i < 4; i++){
		int nx = x + d[i][0];
		int ny = y + d[i][1];
		if(!(nx >= 0 && nx < m && ny >= 0 && ny < n)){
			continue;
		}
		else if(ice[nx][ny] == 1 && !seen[nx][ny]){
			long tmp2 = dfs(nx, ny);
			tmp = tmp<tmp2?tmp2:tmp;
		}
	}
	cnt += tmp;
	seen[x][y] = false;
	return cnt;
}


int main(){
	cin >> m >> n;
	long ans = 0;
	for(int i = 0; i < m; i++)for(int j = 0; j < n; j++)cin >> ice[i][j];
	for(int i = 0; i < m; i++)for(int j = 0; j < n; j++){
		long tmp;
		if(ice[i][j] == 1)tmp = dfs(i,j);
		ans = ans<tmp?tmp:ans;
	}
	cout << ans << endl;
}
	
