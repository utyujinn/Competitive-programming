#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	int grandy[201][201];
	for(int i = 0; i <=200; i++){
		for(int j = 0; j <= 200; j++){
			grandy[i][j] = 0;
		}
	}
	for(int j = 0; j <=100; j++){
		for(int i = 0; i <= 200; i++){
			vector<int> a;
			if(i>0){
				a.push_back(grandy[i-1][j]);
			}
			if(j>0){
				a.push_back(grandy[i+1][j-1]);
			}
			for(int k = 1; k <= i && j>=k; k++){
				a.push_back(grandy[i][j-k]);
			}
			sort(a.begin(), a.end());
			int tmp = 0;
			for(int i = 0; i < a.size(); i++){
				if(tmp == a[i])tmp++;
			}
			grandy[i][j] = tmp;
		}
	}
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
//			cout << grandy[i][j] << " ";
		}
//		cout << endl;
	}
	int ans = 0;
	int w,b;
	for(int i = 0; i < n; i++){
		cin >> w >> b;
		ans ^= grandy[w][b];
	}
	if(ans==0)cout << 1 << endl;
	else cout << 0 << endl;
}
