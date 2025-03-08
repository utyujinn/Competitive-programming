#include<iostream>
using namespace std;
int N,D;
int X[2<<20],Y[2<<20];
long distX[2<<20],distY[2<<20];
long cntX[1<<20],cntY[1<<20];
long cntsumY[1<<20];

int main(){
	cin>>N>>D;
	for(int i=0;i<N;i++){
		int x,y;cin>>x>>y;
		x+=1<<20,y+=1<<20;
		X[x]++,Y[y]++;
		distX[0]+=x;
		distY[0]+=y;
	}
	int cx=0,cy=0;
	for(int i=0;i<(2<<20)-1;i++){
		distX[i+1]=distX[i]+cx-(N-cx);
		distY[i+1]=distY[i]+cy-(N-cy);
		cx+=X[i+1],cy+=Y[i+1];
		if(distX[i+1]<=D){
			cntX[distX[i+1]]+=X[i+1];
		}
		if(distY[i+1]<=D){
			cntY[distY[i+1]]+=Y[i+1];
		}
		cout<<"X "<<i+1-(1<<20)<<" "<<distX[i+1]<<" "<<cx<<endl;
		cout<<"Y "<<i+1-(1<<20)<<" "<<distY[i+1]<<" "<<cy<<endl;
		if(i+1-(1<<20)==10)break;
	}
	cntsumY[0]=cntY[0];
	for(int i=1;i<=D;i++){
		cntsumY[i]+=cntsumY[i-1]+cntY[i];
	}
	long ans=0;
	for(int i=0;i<=D;i++){
		cout<<cntX[i]<<" "<<cntsumY[D-i]<<endl;
		ans+=cntX[i]*cntsumY[D-i];
	}
	cout<<ans<<endl;
}
