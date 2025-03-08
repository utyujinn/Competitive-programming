#include<iostream>
#include<map>
using namespace std;
int A[1<<20];

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	map<int,int> list;
	int ans=0;
	int l=0,r=1;
	while(l<N&&r<N){
		if(A[r]==A[r-1]){
			if(list.find(A[r])!=list.end()&&list[A[r]]>=l){
				l=list[A[r]]+1;
			}
			ans=max(ans,r-l+1);
			list[A[r]]=r;
			r+=2;
		}else{
			l=r+1;
			r+=2;
		}
	}
	list.clear();
	l=1,r=2;
	while(l<N&&r<N){
		if(A[r]==A[r-1]){
			if(list[A[r]]>=l){
				l=list[A[r]]+1;
			}
			ans=max(ans,r-l+1);
			list[A[r]]=r;
			r+=2;
		}else{
			l=r+1;
			r+=2;
		}
	}
	cout<<ans<<endl;
}

