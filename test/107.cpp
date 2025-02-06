#include<iostream>
#include<vector>
using namespace std;

long c[100];

vector<long> vecmul(vector<long> &a, vector<vector<long>> &c, long n){
	vector<long> ret(n,0);
	for(long i = 0; i < n; i++){
		for(long j = 0; j < n; j++){
			ret[i] ^= a[j]&c[j][i];
		}
	}
	return ret;
}

vector<vector<long>> matmul(vector<vector<long>> &a, vector<vector<long>> &b,long n){
	vector<vector<long>> tmp(n,vector<long> (n,0));
	for(long i = 0; i < n; i++){
		for(long j = 0; j < n; j++){
			for(long k = 0; k < n; k++){
				tmp[i][j] ^= a[i][k]&b[k][j];
			}
			cout << tmp[i][j] << " " ;
		}
		cout << endl;
	}
	cout << endl;
	return tmp;
}

vector<vector<long>> matpow(vector<vector<long>> &c, long n, long m){
	vector<vector<long>> ret(n, vector<long>(n,0));
	for(int i = 0; i < n; i++){
		ret[i][i] = 1;
	}
	vector<vector<long>> tmp = c;
	for(long i = 0; i < 31 && m!=0; i++){
		if(m%2){
			cout << "a " << endl;
			ret = matmul(ret,tmp,n);
		}
		tmp = matmul(tmp,tmp,n);
		m>>=1;
	}
	return ret;
}

int main(){
	long K,m;
	cin>>K>>m;
	vector<long> a(m);
	vector<vector<long>> c(K,vector<long> (K));
	for(long i=0;i<K;i++){
		cin >> a[i];
	}
	for(long i=0;i<K;i++){
		cin >> c[i][K-1];
	}
	for(long i = 0; i < K-1; i++){
		c[i+1][i] = 1;
	}
	for(long i = 0; i < K; i++){
		for(long j = 0; j < K; j++){
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	c = matpow(c,K,m-1);
	a = vecmul(a,c,K);
	for(int i = 0; i < K; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	cout << a[0] << endl;
}
