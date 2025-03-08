#include<iostream>
#include<vector>
using namespace std;

int main(){
	int N;
	cin>>N;
	string s;
	cin>>s;
	int co=0;
	for(int i=0;i<N;i++){
		if(s[i]=='1')co++;
	}
	vector<long> dpr[3];
	vector<long> dpl[3];
	for(int i=0;i<3;i++){
		dpr[i].resize(N);
		dpl[i].resize(N);
	}
	dpr[0][0]=1;
	dpr[1][0]=0;
	dpr[2][0]=0;
	dpl[0][0]=0;
	dpl[1][0]=1;
	dpl[2][0]=0;
	long MOD=998244353;
	for(int i=1;i<N;i++){
		dpr[0][i]=(dpl[0][i-1]+dpl[1][i-1]+dpl[2][i-1])%MOD;
		dpr[1][i]=(dpr[0][i-1]+dpr[1][i-1]+dpr[2][i-1])%MOD;
		dpr[2][i]=0;
		dpl[0][i]=0;
		dpl[1][i]=(dpl[0][i-1]+dpl[1][i-1]+dpl[2][i-1])%MOD;
		dpl[2][i]=(dpr[0][i-1]+dpr[1][i-1]+dpr[2][i-1])%MOD;
		dpr[1][i]=min(dpr[1][i],dpl[1][i]);
		dpl[1][i]=min(dpr[1][i],dpl[1][i]);
	}
	long  tmp=min(dpr[1][N-1],dpl[1][N-1]);
	long ans=(dpr[0][N-1]+tmp+dpl[2][N-1])*2%MOD;
	long cnt=2;
	while(co){
		if(co%2){
			ans=ans*cnt%MOD;
		}
		cnt=cnt*cnt%MOD;
		co/=2;
	}
	cout<<ans<<endl;
}
