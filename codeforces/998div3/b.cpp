#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int t;
	cin >> t;
	for(;t--;){
		int n,m;
		cin >> n >> m;
		vector<vector<int>> list(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> list[i][j];
			}
			sort(list[i].begin(), list[i].end());
		}
		vector<pair<int,int>> p(0);
		int flag = 1;
		for(int i = 0; i < n; i++){
			p.emplace_back(list[i][0], i);
			int prev = list[i][0];
			for(int j = 1; j < m; j++){
				if(list[i][j] != prev + n){
					flag = 0;
					break;
				}
				else{
					prev+=n;
				}
			}
			if(flag == 0)break;
		}
		if(flag){
			sort(p.begin(), p.end());
			for(int i = 0; i < n; i++){
				cout << p[i].second+1 << " ";
			}
			cout << endl;
		}
		else{
			cout << -1 << endl;
		}
	}
}
