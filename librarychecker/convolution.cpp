#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long mod=998244353;

long modpow(long a,long n,long mod){
	long ret=1;
	while(n){
		if(n%2)ret=ret*a%mod;
		a=a*a%mod;
		n/=2;
	}
	return ret;
}

long modinv(long a,long mod){
	return modpow(a,mod-2,mod);
}

vector<long> ntt(vector<long> &A,bool inv){
	const long N=A.size();
	int bit_width=0;
	while(1<<bit_width!=N)bit_width++;
	for(int i=0;i<N;i++){
		int now=i;
		int rev=0;
		for(int j=0;j<bit_width;j++){
			rev=(rev<<1)|(now&1);
			now>>=1;
		}
		if(rev>i){
			swap(A[i],A[rev]);
		}
	}
	int width=2,offset=1;
	while(width<=N){
		long w=modpow(3,(mod-1)/width,mod);
		if(inv)w=modinv(w,mod);
		for(int top=0;top<N;top+=width){
			long root = 1;
			for(int i=top;i<top+offset;i++){
				long c0=A[i];
				long c1=A[i+offset];
				A[i]=(c0+c1*root)%mod;
				A[i+offset]=(c0-(c1*root)%mod+mod)%mod;
				root=root*w%mod;
			}
		}
		width<<=1;
		offset<<=1;
	}
	return A;
}

vector<long> convolution(vector<long> A,vector<long> B){
	int IN=A.size()+B.size()-1;
	int N=1;
	while(N<IN){
		N*=2;
	}
	A.resize(N);
	B.resize(N);
	A=ntt(A,true);
	B=ntt(B,true);
	vector<long> C(N);
	for(int i=0;i<N;i++){
		C[i]=A[i]*B[i]%mod;
	}
	C=ntt(C,false);
	for(int i=0;i<N;i++){
		C[i]=(C[i]*modinv(N,mod)%mod);
	}
	return C;
}

int main(){
	int N,M;
	cin>>N>>M;
	vector<long> A(N+M-1),B(N+M-1);
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=0;i<M;i++)cin>>B[i];
	auto C=convolution(A,B);
	for(int i=0;i<N+M-1;i++)cout<<C[i]<<(i==N+M-2?"\n":" ");
}
