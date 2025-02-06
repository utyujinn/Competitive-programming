#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<long> x,y;
	vector<int> x1(n),y1(n),x2(n),y2(n);
	for(int i = 0; i < n; i++){
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		x.push_back(x1[i]);
		x.push_back(x2[i]);
		y.push_back(y1[i]);
		y.push_back(y2[i]);
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	vector<vector<int>> list(2*n, vector<int>(2*n));
	for(int i = 0; i < n; i++){
		x1[i] = lower_bound(x.begin(), x.end(), x1[i]) - x.begin();
		x2[i] = lower_bound(x.begin(), x.end(), x2[i]) - x.begin();
		y1[i] = lower_bound(y.begin(), y.end(), y1[i]) - y.begin();
		y2[i] = lower_bound(y.begin(), y.end(), y2[i]) - y.begin();
		list[x1[i]][y1[i]]++;
		list[x2[i]][y2[i]]++;
		list[x2[i]][y1[i]]--;
		list[x1[i]][y2[i]]--;
	}
	for(int i = 0; i < 2*n; i++){
		for(int j = 1; j < 2*n; j++){
			list[i][j] += list[i][j-1];
		}
	}
	for(int i = 0; i < 2*n; i++){
		for(int j = 1; j < 2*n; j++){
			list[j][i] += list[j-1][i];
		}
	}
	long ans = 0;
	for(int i = 0; i < 2*n; i++){
		for(int j = 0; j < 2*n; j++){
			if(list[i][j]){
				ans += (x[i+1]-x[i])*(y[j+1]-y[j]);
			}
		}
	}
	cout << ans << endl;
}
