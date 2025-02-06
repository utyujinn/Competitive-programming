#include<iostream>
#include<vector>
using namespace std;
int main(){
	int m,n,k;
	cin >> m >> n >> k;
	vector<vector<char>> b(m+1,vector<char>(n+1));
	vector<vector<int>> sumj(m+1,vector<int>(n+1,0));
	vector<vector<int>> sumo(m+1,vector<int>(n+1,0));
	vector<vector<int>> sumi(m+1,vector<int>(n+1,0));
	for(int i =1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			cin >> b[i][j];
			if(i == 1 && j==1){
			}
			else if(j == 1){
				sumj[i][j] = sumj[i-1][j];
				sumo[i][j] = sumo[i-1][j];
				sumi[i][j] = sumi[i-1][j];
			}
			else if(i == 1){
				sumj[i][j] = sumj[i][j-1];
				sumo[i][j] = sumo[i][j-1];
				sumi[i][j] = sumi[i][j-1];
			}
			else{
				sumj[i][j] = sumj[i][j-1] + sumj[i-1][j] - sumj[i-1][j-1];
				sumo[i][j] = sumo[i][j-1] + sumo[i-1][j] - sumo[i-1][j-1];
				sumi[i][j] = sumi[i][j-1] + sumi[i-1][j] - sumi[i-1][j-1];
			}
			if(b[i][j] == 'J')sumj[i][j] ++;
			if(b[i][j] == 'O')sumo[i][j] ++;
			if(b[i][j] == 'I')sumi[i][j] ++;
		}
	}
	for(;k--;){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << sumj[x2][y2]+sumj[x1-1][y1-1]-sumj[x2][y1-1]-sumj[x1-1][y2] << " ";
		cout << sumo[x2][y2]+sumo[x1-1][y1-1]-sumo[x2][y1-1]-sumo[x1-1][y2] << " ";
		cout << sumi[x2][y2]+sumi[x1-1][y1-1]-sumi[x2][y1-1]-sumi[x1-1][y2];
		cout << endl;
	}
}
