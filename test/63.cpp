#include<iostream>
#include<vector>
using namespace std;

int main(){
	long n;
	cin >> n;
	vector<vector<long>> dist(n,vector<long>(n));
	vector<vector<bool>> isroad(n,vector<bool>(n, true));
	for(int i = 0; i < n; i++)for(int j = 0; j < n; j++){
		cin >> dist[i][j];
	}
	long ans = 0;
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(dist[i][j] == dist[i][k]+dist[k][j]){
					if(k != i && j != k)
						isroad[i][j] = false;
				}
				else if(dist[i][j] < dist[i][k]+dist[k][j]){
				}else{
					cout << -1 << endl;
					return 0;
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(isroad[i][j])ans += dist[i][j];
		}
	}
	cout << ans/2 << endl;
}
