#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n,M;
	cin>>n>>M;
	vector<int> A(M);
	for(int i=0;i<M;i++)cin>>A[i];
	sort(A.begin(),A.end());
	int index=0;
	cout<<n-M<<endl;
	for(int i=1;i<=n;i++){
		int ok=M,ng=-1;
		while(ok-ng>1){
			int m=(ok+ng)/2;
			if(A[m]>=i)ok=m;
			else ng=m;
		}
		if(A[ok]!=i)cout<<i<<" ";
	}
	cout<<endl;
}

