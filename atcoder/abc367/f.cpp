#include<iostream>
#include<random>
using namespace std;
int A[2<<17],B[2<<17];
int SA[2<<17],SB[2<<17];
int hs[2<<17];
int MOD = 998244353;

void make_hash(){
	random_device seed_gen;
	default_random_engine engine(seed_gen());
	uniform_int_distribution<> dist(1,MOD);
	for(int i=0;i<(2<<17);i++){
		hs[i]=dist(engine);
	}
}

int main(){
	int N,Q;
	cin>>N>>Q;
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=0;i<N;i++)cin>>B[i];
	make_hash();
	for(int i=0;i<N;i++){
		SA[i+1]=(SA[i]+hs[A[i]])%MOD;
		SB[i+1]=(SB[i]+hs[B[i]])%MOD;
	}
	for(;Q--;){
		int l,r,L,R;
		cin>>l>>r>>L>>R;
		if((SA[r]-SA[l-1]+MOD)%MOD==(SB[R]-SB[L-1]+MOD)%MOD){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
}
