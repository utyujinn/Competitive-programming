#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<class T>
T modpow(T A,T N,T M){
	T res=1;
	A%=M;
	while(N){
		if(N&1)res=res*A%M;
		A=A*A%M;
		N>>=1;
	}
	return res;
}

bool MillarRabin(long long N, vector<long long> A){
	int s=0;
	long long d=N-1;
	while(d%2==0){
		s++;
		d/=2;
	}
	for(long long a:A){
		if(N<=a)return true;
		long long x=modpow<__int128_t>(a,d,N);
		if(x==1)continue;
		int t;
		for(t=0;t<s;t++){
			if(x==N-1)break;
			x=__int128_t(x)*x%N;
		}
		if(t==s)return false;
	}
	return true;
}

bool isPrime(long long N){
	if(N==1)return false;
	if(N==2)return true;
	if(N%2==0)return false;
	if(N<4759123141LL){
		return MillarRabin(N,{2,7,61});
	}else{
		return MillarRabin(N,{2,325,9375,28178,450775,9780504,1795265022});
	}	
}

long long gcd(long long a,long long b){
	if(b==0)return a;
	else return gcd(b,a%b);
}

long long f(long long X,long long c,long long N){
	return (X*X+c)%N;
}

long long find_prime_factor(long long N){
	if(N%2==0)return 2;
	for(int c=1;c<N;c++){
		long long X=0,Y=0;
		long long g=1;
		while(g==1){
			X=f(X,c,N);
			Y=f(f(Y,c,N),c,N);
			g=gcd(abs(X-Y),N);
		}
		if(g==N)continue;
		if(isPrime(g)){
			return g;
		}else if(isPrime(N/g)){
			return N/g;
		}else{
			return find_prime_factor(g);
		}
	}
}

vector<pair<long long, long long> > PollardRho(long long N){
	vector<pair<long long, long long> > prime_list;
	while(!isPrime(N) && N!=1){
		long long fac=find_prime_factor(N);
		int count=0;
		while(N%fac==0){
			N/=fac;
			count++;
		}
		prime_list.push_back(make_pair(fac,count));
	}
	if(N!=1){
		prime_list.push_back(make_pair(N,1));
	}
	sort(prime_list.begin(), prime_list.end());
	return prime_list;
}

void solve(){
	long long N;
	cin>>N;
	auto prime_pair = PollardRho(N);
	int sum=0;
	for(auto[prime,cnt]:prime_pair){
		sum+=cnt;
	}
	cout<<sum<<" ";
	for(auto[prime,cnt]:prime_pair){
		for(;cnt--;){
			cout<<prime<<" ";
		}
	}
	cout<<endl;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	long long t;
	cin >> t;
	for(;t--;){
		solve();
	}
}

