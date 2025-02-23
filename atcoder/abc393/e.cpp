#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int cnt[1<<20];
int b[1<<20];
int ans[1<<20];

int main(){
	int N,K;
	cin>>N>>K;
	vector<int> A(N);
	for(int i=0;i<1<<20;i++){
		cnt[i]=0,b[i]=0,ans[i]=1;
	}
	for(int i=0;i<N;i++){
		cin>>A[i];
		cnt[A[i]]++;
	}
	for(int i=1;i<1<<20;i++){
		for(int j=i;j<1<<20;j+=i){
			b[i]+=cnt[j];
		}
		if(b[i]>=K){
			for(int j=i;j<1<<20;j+=i){
				ans[j]=i;
			}
		}
	}
	for(int i=0;i<N;i++){
		cout<<ans[A[i]]<<endl;
	}
}

