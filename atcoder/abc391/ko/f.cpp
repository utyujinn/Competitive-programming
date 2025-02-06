#include<iostream>
#include<queue>
#include<algorithm>
#include<set>
#include<tuple>
using namespace std;
int N,K;
long A[2<<17],B[2<<17],C[2<<17];
long f(int i,int j,int k){return A[i]*B[j]+B[j]*C[k]+C[k]*A[i];}

int main(){
	cin>>N>>K;
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=0;i<N;i++)cin>>B[i];
	for(int i=0;i<N;i++)cin>>C[i];
	sort(A,A+N);
	sort(B,B+N);
	sort(C,C+N);
	priority_queue<pair<long,tuple<int,int,int>>> Q;
	Q.push(make_pair(f(N-1,N-1,N-1),make_tuple(N-1,N-1,N-1)));
	set<tuple<int,int,int>>S;
	S.insert(make_tuple(N-1,N-1,N-1));
	for(int v=1;v<K;v++){
		auto[_,ijk]=Q.top();Q.pop();
		auto[i,j,k]=ijk;
		if(i>0)
		{
			auto t=make_tuple(i-1,j,k);
			if(S.find(t)==S.end())
			{
				S.insert(t);
				Q.push(make_pair(f(i-1,j,k),t));
			}
		}
		if(j>0)
		{
			auto t=make_tuple(i,j-1,k);
			if(S.find(t)==S.end())
			{
				S.insert(t);
				Q.push(make_pair(f(i,j-1,k),t));
			}
		}
		if(k>0)
		{
			auto t=make_tuple(i,j,k-1);
			if(S.find(t)==S.end())
			{
				S.insert(t);
				Q.push(make_pair(f(i,j,k-1),t));
			}
		}
	}
	cout << Q.top().first << endl;
}
