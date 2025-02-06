#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n,K;
	cin >> n >> K;
	long ans = 0;
	vector<int> s[3];
	vector<int> e[3];
	vector<long> c[3];
	vector<vector<vector<int>>> list(2*n, vector<vector<int>>(2*n, vector<int> (2*n,0)));
	for(int i = 0; i < n; i++){
		int tmp;
		for(int k = 0; k < 3; k++){
			cin >> tmp;
			s[k].push_back(tmp);
			c[k].push_back(tmp);
		}
		for(int k = 0; k < 3; k++){
			cin >> tmp;
			e[k].push_back(tmp);
			c[k].push_back(tmp);
		}
	}
	for(int i = 0; i < 3; i++){
		sort(c[i].begin(), c[i].end());
		c[i].erase(unique(c[i].begin(), c[i].end()), c[i].end());
		for(int j = 0; j < n; j++){
			s[i][j] = lower_bound(c[i].begin(), c[i].end(), s[i][j])-c[i].begin();
			e[i][j] = lower_bound(c[i].begin(), c[i].end(), e[i][j])-c[i].begin();
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = s[0][i];j < e[0][i]; j++){
			for(int k = s[1][i]; k < e[1][i]; k++){
				for(int l = s[2][i]; l < e[2][i]; l++){
					list[j][k][l]++;
				}
			}
		}
	}
	for(int i = 0; i < 2*n-1; i++){
		for(int j = 0; j < 2*n-1; j++){
			for(int k = 0; k < 2*n-1; k++){
				if(list[i][j][k] >= K){
					long tmp = (c[0][i+1]-c[0][i])*(c[1][j+1]-c[1][j])*(c[2][k+1]-c[2][k]);
					ans += tmp;
				}
			}
		}
	}
	cout << ans << endl;
}
