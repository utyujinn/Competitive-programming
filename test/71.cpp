#include<iostream>
#include<vector>
using namespace std;

long modpow(long a, long b, long mod){
	long res = 1;
	for(int i = 0; i < 31; i++){
		if((b>>i)%2 == 1)res = (res*a)%mod;
		a = (a*a)%mod;
	}
	return res;
}

int main(){
	int n,q;
	cin >> n >> q;
	vector<long> a(n);
	vector<long> dist(n);
	vector<long> imosu(n);
	long mod = 1000000007;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(i > 0)dist[i-1] = modpow(a[i-1], a[i], 1000000007);
	}
	long prev = 0;
	for(int i = 0; i < q; i++){
		long tmp;
		cin >> tmp;
		tmp--;
		if(prev < tmp){
			imosu[prev]++;
			imosu[tmp]--;
		}else{
			imosu[tmp]++;
			imosu[prev]--;
		}
		if(i==q-1){
			imosu[tmp]--;
			imosu[0]++;
		}
		prev = tmp;
	}
	long ans = 0;
	long cur = 0;
	for(int i = 0; i < n; i++){
		cur += imosu[i];
		ans = (ans + (cur * dist[i])%mod)%mod;
	}
	cout << ans << endl;
}
