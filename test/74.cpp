#include<iostream>
#include<vector>
using namespace std;

int main(){
	long n,k;
	cin >> n >> k;
	long a = k+n-1;
	vector<long> fac(a+1);
	vector<long> inv(a+1,1);
	vector<long> finv(a+1);
	fac[0]=1;
	fac[1] = 1;
	inv[1] = 1;
	finv[0] = 1;
	finv[1] = 1;
	long mod = 1000000007;
	for(int i = 2; i < a+1; i++){
		fac[i] = fac[i-1] * i % mod;
		long tmp = i;
		for(int j = 0; j < 32; j++){
			if(((mod-2)>>j)%2==1){
				inv[i] *= tmp;
				inv[i] %= mod;
			}
			tmp = tmp * tmp % mod;
		}
		finv[i] = finv[i-1] * inv[i] % mod;
	}
	cout << fac[a] * finv[k] % mod * finv[n-1] % mod << endl;
}
