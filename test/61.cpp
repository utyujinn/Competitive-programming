#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<long>> dist(n,vector<long>(n, 1LL<<60));
	vector<int> a(m),b(m),t(m);
	for(int i = 0; i < n; i++){
		dist[i][i] = 0;
	}
	for(int i=  0; i < m; i++){
		cin >> a[i] >> b[i] >> t[i];
		a[i]--;b[i]--;
		dist[a[i]][b[i]] = t[i];
		dist[b[i]][a[i]] = t[i];
	}
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				dist[i][j] = dist[i][j]>(dist[i][k] + dist[k][j])?(dist[i][k] + dist[k][j]):dist[i][j];
			}
		}
	}
	long ans = 1LL<<60;
	for(int i = 0; i < n; i++){
		int max = 0;
		for(int j = 0; j < n; j++){
			max = max<dist[i][j]?dist[i][j]:max;
		}
		ans = ans>max?max:ans;
	}
	cout << ans << endl;
}
