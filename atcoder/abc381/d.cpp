#include<iostream>
using namespace std;
int A[1<<20];

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	int ans=0;
	int l=0,r=1;
	int cl=0;
	while(l<N&&r<N){
		if(A[r]==A[r-1] && A[r]==A[l] && r>l+2){
			l+=2;
			cl-=2;
		}
		else if(A[r]==A[r-1]){
			cl+=2;
			r+=2;
		}else{
			cl=0;
			r++;
			l=r-1;
		}
		ans=max(ans,cl);
	}
	cout<<ans<<endl;
}
