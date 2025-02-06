#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int h,w;
	cin >> h >> w;
	vector<vector<char>> s(h, vector<char>(w));
	int minh = h,maxh = -1, minw = w, maxw = -1;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin >> s[i][j];
			if(s[i][j] == '#'){
				minh = min(i,minh);
				maxh = max(i,maxh);
				minw = min(j,minw);
				maxw = max(j,maxw);
			}
		}
	}
	for(int i = minh;i <= maxh; i++){
		for(int j = minw; j <= maxw; j++){
			if(s[i][j] == '.'){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
}
