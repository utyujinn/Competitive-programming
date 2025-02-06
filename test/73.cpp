#include<iostream>
#include<vector>

using namespace std;

int main(){
	long x,y;
	cin >> x >> y;
	if((x+y)%3 != 0){
		cout << 0 << endl;
		return 0;
	}
	long n = (x+y)/3;
	long r = max(x-n, y-n); 
	if(r > n){
		cout << 0 << endl;
		return 0;
	}
	long mod = 1000000007;
	vector<long> fav(n+1,0);
	vector<long> inv(n+1,1);
	vector<long> finv(n+1,0);
	fav[0] = 1;
	fav[1] = 1;
	inv[1] = 1;
	finv[0] = 1;
	finv[1] = 1;
	for(int i = 2; i <= n; i++){
		fav[i] = (fav[i-1]*i)%mod;
		long tmp = i;
		for(int j = 0; j <= 32; j++){
			if(((mod-2)>>j)%2==1){
				inv[i] = (inv[i] * tmp) % mod;
			}
			tmp = (tmp * tmp) % mod;
		}
		finv[i] = (finv[i-1]*inv[i])%mod;
	}
	cout << (((fav[n]%mod)*(finv[r]%mod))%mod)*(finv[n-r]%mod)%mod << endl;
}
