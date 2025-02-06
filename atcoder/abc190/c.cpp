#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> a(m),b(m);
	for(int i = 0; i < m; i++){
		cin >> a[i] >> b[i] ;
		a[i]--;b[i]--;
	}
	int k;
	cin >> k;
	vector<int> c(k),d(k);
	for(int i = 0; i < k; i++){
		cin >> c[i] >> d[i] ;
		c[i]--;d[i]--;
	}
	int ans = 0;
	for(int i = 0; i < pow(2,k); i++){
		int cnt = 0;
		vector<int> aa(n,0);
		for(int j=0; j < k; j++){
			if((i>>j)%2 == 1){
				aa[d[j]] = 1;
			}
			else{
				aa[c[j]] = 1;
			}
		}
		for(int j = 0; j < m; j++){
			if(aa[a[j]] == 1 && aa[b[j]] == 1)cnt++;
		}
		if(cnt > ans) ans = cnt;
	}

	cout << ans << endl;
}
