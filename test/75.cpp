#include<iostream>
#include<vector>
using namespace std;
long mod = 1000000007;

long mpow(long x, long y, long mod){
	long res = 1;
	long mul = x;
	for(int i = 0; i < 60; i++){
		if((y>>i)%2==1){
			res = (res * mul) % mod;
		}
		mul = (mul*mul)%mod;
	}
	return res;
}

int dfs(int i,vector<vector<int>> G, vector<bool> seen){
	seen[i] = true;
	int cnt = 0;
	cnt++;
	for(int next: G[i]){
		if(!seen[next]){
			cnt += dfs(next,G,seen);
		}
	}
	return cnt;
}

int main(){
	int n;
	cin >> n;
	vector<vector<int>> G(n);
	for(int i = 0; i < n-1; i++){
		int a,b;
		cin >> a >> b;
		a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<bool> seen(n);
	long ans = 0;
	for(int i = 0; i < n; i++){
		vector<int> list(0);
		seen.assign(n,false);
		seen[i] = true;
		for(int next: G[i]){
			list.push_back(dfs(next, G, seen));
		}
		long tmp = 0;
		if(list.size()>1){
		for(int i = 0; i < list.size(); i++){
			tmp += mpow(2,list[i],mod);
		}
		tmp--;
		ans += mpow(2,n-1,mod)-tmp;
		cout << ans << endl;
		}
	}
	cout << ans << endl;
	long tmp = mpow(2,(mod-2)*n, mod);
	ans = (ans * tmp) % mod;
	cout << ans << endl;
}
