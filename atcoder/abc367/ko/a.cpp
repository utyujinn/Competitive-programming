#include<iostream>
#include<random>
using namespace std;
const int SZ=10;
int H[SZ][200001];
int N,Q;
int A[2<<17],B[2<<17];
long SA[SZ][2<<17];
int ZA[SZ][2<<17];
int ZB[SZ][2<<17];
long SB[SZ][2<<17];
int main(){
	cin>>N>>Q;
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=0;i<N;i++)cin>>B[i];
	random_device seed;
	mt19937 rng(seed());
	for(int k=0;k<SZ;k++)for(int i=1;i<=N;i++)
	{
		H[k][i]=rng();
	}
	for(int k=0;k<SZ;k++)
	{
		for(int i=0;i<N;i++)
		{
			SA[k][i+1]=SA[k][i]+H[k][A[i]];
			ZA[k][i+1]=ZA[k][i]^H[k][A[i]];
			SB[k][i+1]=SB[k][i]+H[k][B[i]];
			ZB[k][i+1]=ZB[k][i]^H[k][B[i]];
		}
	}
	for(;Q--;){
		int a,b,c,d;cin>>a>>b>>c>>d;
		a--,c--;
		if(b-a!=d-c){
			cout<<"No"<<endl;
			continue;
		}
		bool fn=false;
		for(int k=0;k<SZ;k++){
			if(SA[k][b]-SA[k][a]!=SB[k][d]-SB[k][c])fn=true;
			if((ZA[k][b]^ZA[k][a])!=(ZB[k][d]^ZB[k][c]))fn=true;
		}
		cout<<(fn?"No":"Yes")<<endl;
	}
}
