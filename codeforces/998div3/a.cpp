#include<iostream>
#include<vector>

using namespace std;

void solve(){
	vector<int> a(5);
	cin >> a[0] >> a[1] >> a[3] >> a[4];
	int ans = 0;
	for(int i = -100; i <= 100; i++){
		int tmp = 0;
		a[2] = i;
		for(int j = 0; j < 3; j++){
			if(a[j]+a[j+1]==a[j+2]){
				tmp++;
			}
		}
		ans = max(ans, tmp);
	}
	cout << ans << endl;
}

int main(){
	int t;
	cin >> t;
	for(;t--;)solve();
}
