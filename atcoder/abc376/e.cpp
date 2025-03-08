#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

void solve(){
	int N,K;
	cin>>N>>K;
	vector<int> A(N),B(N);
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=0;i<N;i++)cin>>B[i];
	vector<pair<int,int>> AB(N);
	for(int i=0;i<N;i++)AB[i]=make_pair(A[i],B[i]);
	sort(AB.begin(),AB.end());
	priority_queue<int> q;
	int a=0;
	long b=0;
	long ans=~0LLU>>1;
	for(int i=0;i<K;i++){
		a=max(AB[i].first,a);
		b+=AB[i].second;
		q.push(AB[i].second);
	}
	ans=a*b;
	for(int i=K;i<N;i++){
		q.push(AB[i].second);
		a=max(AB[i].first,a);
		b+=AB[i].second;
		b-=q.top();
		q.pop();
		ans=min(ans,a*b);
	}
	cout<<ans<<endl;
}

int main(){
	int T;
	cin>>T;
	for(;T--;){
		solve();
	}
}
