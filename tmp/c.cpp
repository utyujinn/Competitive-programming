#include<iostream>
#include<vector>
using namespace std;

template<class T>
T modpow(T A, T N, T M){
	T res = 1;
	A%=M;
	while(N){
		if(N&1==1)res=(res*A)%M;
		A=(A*A)%M;
		N>>=1;
	}
	return res;
}

bool MillerRabin(long long N, vector<long long> A){
	long long s = 0, d= N-1;
	while(d%2==0){
		s++;
		d>>=1;
	}
	for(auto a:A){
		if(N<=a)return true;
		long long t,x = modpow<__int128_t>(a,d,N);
		if(x!=1){
			for(t=0;t<s;t++){
				if(x==N-1)break;
				x=__int128_t(x)*x%N;
			}
			if(t==s)return false;
		}
	}
	return true;
}

bool isPrime(long long N){
	if(N<=1)return false;
	if(N==2)return true;
	if(N%2==0)return false;
	if(N<4759123141LL)
		return MillerRabin(N,{2,7,61});
	else
		return MillerRabin(N,{2,325,9375,28178,450775,9780504,1795265022});
}

int main(){
	int t; 
	cin>>t;
	for(;t--;){
		long n;
		cin >> n;
		cout << (isPrime(n)?"Yes":"No") << endl;
	}
}
