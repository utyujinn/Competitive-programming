#include<iostream>
#include<cmath>
using namespace std;
bool list[1<<20];
int pr[16]={3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};

long lpow(int x,int y){
	long ret=1;
	for(int i=0;i<y;i++){
		ret*=x;
	}
	return ret;
}

int main(){
	long N;cin>>N;
	long ok=1LL<<32,ng=-1;
	long ans=0;
	while(ok-ng>1){
		long mid=(ok+ng)/2;
		if(mid*mid<=N)ng=mid;
		else ok=mid;
	}
	ans+=ng;
	for(int i=1;i*i<(1<<20);i++){
		list[i*i]=true;
	}
	for(int p:pr){
		int i=1;
		while(true){
			if(pow(i,p)>1e18)break;
			if(!list[i]){
				if(lpow(i,p)<=N)ans++;
				if(lpow(i,p)<(1<<20))list[lpow(i,p)]=true;
			}
			i++;
		}
	}
	cout<<ans<<endl;
}
