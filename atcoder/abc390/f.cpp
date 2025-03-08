#include<iostream>
using namespace std;
int N;
int PC[3<<17];//c

int main(){
	cin>>N;
	for(int i=0;i<=N;i++){
		PC[i]=-1;
	}
	long ans=0;
	for(int i=0;i<N;i++){
		int A;cin>>A;
		ans+=(i-PC[A])*(i-PC[A]-1)/2;
		int pc2=max(PC[A],PC[A-1]);
		ans-=(i-pc2)*(i-pc2-1)/2;
		PC[A]=i;
		for(int i=0;i<=N;i++)cout<<PC[i]<<(i==N?"\n":" ");
	}
	for(int i=0;i<=N;i++){
		if(PC[i]!=-1){
			//ans+=(N-PC[i])*(N-PC[i]-1)/2;
		}
	}
	cout<<ans<<endl;
}
