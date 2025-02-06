#include<iostream>
#include<vector>
using namespace std;

int main(){
	long h,w;
	cin >> h >> w;
	vector<vector<long>> dist(10,vector<long>(10));
	for(int i = 0; i < 10; i++)for(int j = 0; j < 10; j++){
		cin >> dist[i][j];
	}
	for(int k = 0; k < 10; k++){
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 10; j++){
				dist[i][j] = dist[i][j]>(dist[i][k]+dist[k][j])?(dist[i][k]+dist[k][j]):dist[i][j];
			}
		}
	}
	long ans = 0;
	for(int i = 0; i < h; i++)for(int j =0; j < w; j++){
		long a;
		cin >> a;
		if(a!=-1)ans+= dist[a][1];
	}
	cout << ans << endl;
}
