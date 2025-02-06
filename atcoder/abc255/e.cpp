#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main(){
	long n,m;
	cin >> n >> m;
	vector<long> s(n);
	vector<long> x(m);
	for(int i = 0; i < n-1; i++){
		cin >> s[i];
	}
	for(int i = 0; i < m; i++){
		cin >> x[i];
	}
	sort(x.begin(), x.end());
	vector<long> a(n);
	vector<long> b(n);
	b[0] = 0;
	for(int i = 1; i < n; i++){
		b[i] = s[i-1]-b[i-1];
	}
	
	map<long,long> mp;
	vector<vector<long>> c(n,vector<long>(m,0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			c[i][j] = (x[j]-b[i])*(i%2?-1:1);
			mp[c[i][j]]++;
		}
	}

	long ans = 0;
	for(auto p: mp) if(p.second > ans) ans = p.second;

	cout << ans << endl;
}
