#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
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
	long long m=pow(N,0.125)+1;
	for(int c=1;c<N;c++){
		long long X,Y=0,Ys=0;
		long long g=1,q=1,r=1,k=0;
		while(g==1){
			X=Y;
			while(k<3*r/4){
				Y=f(Y,c,N);
				k+=1;
			}
			while(k<r && g==1){
				Ys=Y;
				for(int i=0;i<min(m,r-k);i++){
					Y=f(Y,c,N);
					q=__int128_t(q)*abs(X-Y)%N;
				}
				g=gcd(q,N);
				k+=m;
			}
			k=r;
			r*=2;
		}
		if(g==N){
			g=1;
			Y=Ys;
			while(g==1){
				Y=f(Y,c,N);
				g=gcd(abs(X-Y),N);
			}
		}
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
	int t;
	cin >> t;
	for(;t--;){
		solve();
	}
}
