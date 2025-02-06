#include<iostream>
#include<vector>

using namespace std;

int main(){
	long h,w,k;
	long v;
	cin >> h >> w >> k >> v;
	vector<vector<long>> a(h+1, vector<long>(w+1,0));
	vector<vector<long>> sum(h+1, vector<long>(w+1,0));

	for(int i = 1; i <= h; i++)for(int j = 1; j <= w; j++){
		cin >> a[i][j];
		sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
	}

	long ans = 0;
	for(int i = 1; i <= h; i++)for(int j = 1; j <= w; j++){
		for(int ii = i; ii <= h; ii++)for(int jj = j; jj <= w; jj++){
			if((sum[ii][jj] + sum[i-1][j-1] - sum[ii][j-1] - sum[i-1][jj]) + (ii-i+1)*(jj-j+1)*k <= v){
				ans = ans<(ii-i+1)*(jj-j+1)?(ii-i+1)*(jj-j+1):ans;
			}
		}
	}
	cout << ans << endl;
}
