#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	int sn = int(sqrt(n));
	vector<int> lp(sn+1,0);
	vector<vector<int>> lc(sn+1, vector<int>(sn+1,0));
	int pt,t,l,r;
	pt = 0;
	long ans = 0;
	for(int i = 0; i < m; i++){
		cin >> t >> l >> r;
		for(int i = 0; i < sn+1; i++){
			lp[i] += t*sn;
		}
		lp[sn] = (n%sn)*t;
		l--,r--;
		int ln = l/sn, rn = r/sn;
		if(ln==rn){
			for(int i = l%sn; i <= r%sn; i++){
				ans += lc[ln][i];
				lp[ln] -= lc[ln][i];
				lc[ln][i] = 0;
			}
		}
		else{
			for(int i = l%sn; i < sn+1; i++){
				ans += lc[ln][i];
				lp[ln] -= lc[ln][i];
				lc[ln][i] = 0;
			}
			for(int i = ln + 1; i < sn-1; i++){
				ans += lp[];
		}
	}

	
	cout << ans << endl;
}
