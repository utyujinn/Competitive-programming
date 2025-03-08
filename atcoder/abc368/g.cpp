#include<iostream>
using namespace std;
int A[1<<17],B[1<<17];

int main(){
	int N;cin>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=0;i<N;i++)cin>>B[i];
	int Q;cin>>Q;
	for(int i=0;i<Q;i++){
		int q;cin>>q;
		if(q==1){
			int i,x;cin>>i>>x;i--;
			A[i]=x;
		}
		if(q==2){
			int i,x;cin>>i>>x;i--;
			B[i]=x;
		}
		if(q==3){
			int l,r;cin>>l>>r;l--,r--;
			long v=0;
			for(int j=l;j<=r;j++){
				if(v+A[j]>v*B[j]){
					v=v+A[j];
				}else{
					v=v*B[j];
				}
			}
			cout<<v<<endl;
		}
	}
}
