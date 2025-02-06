#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<long> x1(n),y1(n),x2(n),y2(n);
	for(int i = 0; i < n; i++){
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
	}
	vector<long> x(0), y(0);
	x.insert(x.end(),x1.begin(), x1.end());
	x.insert(x.end(),x2.begin(), x2.end());
	y.insert(y.end(),y1.begin(), y1.end());
	y.insert(y.end(),y2.begin(), y2.end());
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	for(int i = 0; i < n; i++){
		long ok = 2*n, ng = -1;
		while(ok-ng>1){
			long mid = (ok+ng)/2;
			if(x[mid] >= x1[i]) ok = mid;
			else ng = mid;
		}
		x1[i] = ok;
		ok = 2*n, ng = -1;
		while(ok-ng>1){
			long mid = (ok+ng)/2;
			if(x[mid] >= x2[i]) ok = mid;
			else ng = mid;
		}
		x2[i] = ok;
		ok = 2*n, ng = -1;
		while(ok-ng>1){
			long mid = (ok+ng)/2;
			if(y[mid] >= y1[i]) ok = mid;
			else ng = mid;
		}
		y1[i] = ok;
		ok = 2*n, ng = -1;
		while(ok-ng>1){
			long mid = (ok+ng)/2;
			if(y[mid] >= y2[i]) ok = mid;
			else ng = mid;
		}
		y2[i] = ok;
	}
	vector list(n*2+1, vector<long> (n*2+1, 0));
	for(int i = 0; i < n; i++){
		list[x1[i]][y1[i]]++;
		list[x2[i]][y2[i]]++;
		list[x1[i]][y2[i]]--;
		list[x2[i]][y1[i]]--;
	}
	for(int i = 1; i <= n*2; i++){
		for(int j = 0; j <= n*2; j++){
			list[i][j] += list[i-1][j];
		}
	}
	for(int i = 0; i <= n*2; i++){
		for(int j = 1; j <= n*2; j++){
			list[i][j] += list[i][j-1];
		}
	}
	long ans = 0;
	for(int i = 0; i <= n*2; i++){
		for(int j = 0; j <= n*2; j++){
			if(list[i][j]){
				ans += (x[i+1] - x[i])*(y[j+1] - y[j]);
			}
		}
	}
	cout << ans << endl;
}
