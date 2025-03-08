#include<iostream>
using namespace std;
int N,X;
long A[100],P[100],B[100],Q[100];

int main(void){
	cin>>N>>X;
	for(int i=0;i<N;i++)cin>>A[i]>>P[i]>>B[i]>>Q[i];
	long ok=1LL<<30,ng=-1;
	while(ok-ng>1){
		long mid=(ok+ng)/2;
		long cnt=0;
		for(long i=0;i<N;i++){
			long tmp=~0ULL>>2;
			for(long j=0;j<=B[i];j++){
				long a=A[i]*j;//amount of already processed product
				long k;
				if(mid-a>0)k=(mid-a+B[i]-1)/B[i];
				else k=0;
				tmp=min(tmp,j*P[i]+k*Q[i]);
			}
			for(long j=0;j<=A[i];j++){
				long a=B[i]*j;//amount of already processed product
				long k;
				if(mid-a>0)k=(mid-a+A[i]-1)/A[i];
				else k=0;
				tmp=min(tmp,j*Q[i]+k*P[i]);
			}
			cnt+=tmp;
			if(cnt>X)break;
		}
		if(cnt<=X){
			ng=mid;
		}
		else{
			ok=mid;
		}
//		cout<<cnt<<" "<<ng<<" "<<ok<<endl;
	}
	cout<<ng<<endl;
}
