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

vector<long> make_root(long mod){
	vector<long> ret;
	long r=modpow(3,119,mod);
	for(int i=0;i<23;i++){
		ret.push_back(r);
		r=(r*r)%mod;
	}
	reverse(ret.begin(),ret.end());
	return ret;
}

vector<long> make_invroot(vector<long> &root,long mod){
	vector<long> ret;
	for(long i=0;i<root.size();i++){
		ret.push_back(modinv(root[i],mod));
	}
	return ret;
}

vector<long> ntt(vector<long> &A,long depth,vector<long> &root){
	const long N=A.size();
	if(N==1)return A;
	vector<long> even(N/2),odd(N/2);
	for(int i=0;i<N;i++){
		if(i%2==0)even[i/2]=A[i];
		else odd[i/2]=A[i];
	}
	even=ntt(even,depth-1,root);
	odd=ntt(odd,depth-1,root);
	long r=root[depth];
	long now=1;
	for(int i=0;i<N;i++){
		A[i]=(even[i%(N/2)]+(now*odd[i%(N/2)]%mod))%mod;
		now=(now*r)%mod;
	}
	return A;
}

vector<long> convolution(vector<long> A,vector<long> B){
	int IN=A.size()+B.size()-1;
	int N=1;
	int log_2n=0;
	while(N<IN){
		N*=2;
		log_2n++;
	}
	A.resize(N);
	B.resize(N);
	auto root=make_root(mod);
	auto invroot=make_invroot(root,mod);
	vector<long> DA=ntt(A,log_2n-1,root);
	for(int i=0;i<N;i++)cout<<DA[i]<<(i==N-1?"\n":" ");
	vector<long> DB=ntt(B,log_2n-1,root);
	for(int i=0;i<N;i++)cout<<DB[i]<<(i==N-1?"\n":" ");
	vector<long> DC(N);
	for(int i=0;i<N;i++){
		DC[i]=DA[i]*DB[i]%mod;
	}
	vector<long> C=ntt(DC,log_2n-1,invroot);
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
