#include<iostream>
#include<vector>
using namespace std;

int main(){
	long r,c;
	cin >> r >> c;
	vector<vector<int>> s(r,vector<int>(c));
	for(int i = 0; i < r; i++)for(int j = 0; j < c; j++)cin >> s[i][j];
	long ans = 0;
	for(int i = 0; i < 1<<r; i++){
		long tmp = 0;
		for(int j = 0; j < c; j++){
			long tmp2 = 0;
			for(int k = 0; k < r; k++){
				if(!(1<<k & i) ^ s[k][j])tmp2++;
			}
			tmp += max(tmp2, r-tmp2);
		}
		ans = ans<tmp?tmp:ans;
	}
	cout << ans << endl;
}
