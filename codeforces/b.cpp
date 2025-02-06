#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(;t--;){
		int n,l,r;
		cin >> n >> l >> r;
		vector<long long> a(l-1), b(r-l+1), c(n-r);
		long long ans = 0;
		for(int i = 0; i < l-1; i++){
			cin >> a[i];
		}
		for(int i = 0; i < r-l+1; i++){
			cin >> b[i];
			ans += b[i];
		}
		for(int i = 0; i < n-r; i++){
			cin >> c[i];
		}

		sort(a.begin(), a.end());
		sort(b.rbegin(), b.rend());
		sort(c.begin(), c.end());

		long long suma = 0, sumb = 0, sumc = 0;
		long long sub = 0;

		for(int i = 0; i < r-l+1; i++){
			sumb += b[i];
			if(a.size()>i){
				suma += a[i];
				sub = max(sub, sumb-suma);
			}
			if(c.size()>i){
				sumc += c[i];
				sub = max(sub, sumb-sumc);
			}
		}
		cout << ans-sub << endl;
	}
}
