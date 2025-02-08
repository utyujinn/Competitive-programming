#include <iostream>

using namespace std;

#define rep(i,n) for(int i=0; i<(int)(n); i++)

typedef unsigned int uint;

int K, M;
uint a[100], c[100][100], x[100][100], ans;

void mul(uint u[][100], uint v[][100]){
	uint t[K][K];
	fill(t[0], t[K], 0);
	rep(i,K) rep(j,K) rep(k,K) t[i][j] ^= u[i][k] & v[k][j];
	rep(i,K) rep(j,K) u[i][j] = t[i][j];
}

void print(uint u[][100]){
	cout << endl;
	for(int i=0;i<K;i++){
		for(int j=0;j<K;j++){
			cout<<c[i][j]<< " "; 
		}
		cout<<endl;
	}
}

int main(){
	cin >> K >> M;
	rep(i,K) cin >> a[i];
	rep(i,K) cin >> c[0][i];
	rep(i,K-1) c[i+1][i]--;
	
	rep(i,K) x[i][i]--;
	print(c);
	for(int n=M-1; n; n/=2){
		if(n%2) mul(x,c);
		mul(c,c);
		print(c);
	}
	
	rep(i,K) ans ^= x[K-1][i] & a[K-1-i];
	cout << ans << endl;
	return 0;
}

