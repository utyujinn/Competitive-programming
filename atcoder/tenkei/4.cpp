#include<iostream>
#include<vector>
using namespace std;
int main(){
	int h,w;
	cin >> h >> w;
	vector<vector<int>> a(h,vector<int>(w));
	vector<int> rsum(h);
	vector<int> csum(w);
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin >> a[i][j];
			rsum[i]+= a[i][j];
			csum[j]+= a[i][j];
		}
	}
	for(int i = 0;i  < h; i++){
		for(int j = 0; j < w; j++){
			cout << rsum[i] + csum[j] - a[i][j] << " ";
		}
		cout << endl;
	}
}
