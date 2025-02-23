#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int N,M;
	cin>>N>>M;
	vector<long> X(M),A(M);
	long sum=0;
	for(int i=0;i<M;i++){
		cin>>X[i];
		X[i]--;
	}
	for(int i=0;i<M;i++){
		cin>>A[i];
		sum+=A[i];
	}
	vector<pair<long,long>> XA;
	for(int i=0;i<M;i++)XA.emplace_back(X[i],A[i]);
	sort(XA.begin(),XA.end());
	for(int i=0;i<M;i++){
		X[i]=XA[i].first;
		A[i]=XA[i].second;
	}
	long prev=N;
	long ans=0;
	long must=0;
	for(int i=M-1;i>=0;i--){
		must+=prev-X[i]-1;
		if(A[i]-1>=must){
			ans+=must*(must+1)/2;
			must=0;
		}else{
			ans+=must*(must+1)/2-(must-A[i]+1)*(must-A[i]+2)/2;
			must-=A[i]-1;
			ans+=must;
		}
		prev=X[i];
	}
	if(sum!=N||must||prev!=0)cout<<-1<<endl;
	else cout<<ans<<endl;
}
