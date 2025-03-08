#include<iostream>
#include<vector>
using namespace std;

struct LIS{
	int N;
	vector<int> dp;
	LIS(vector<int> &A):N(A.size()){
		dp.resize(N,~0U>>0);
		for(int i=0;i<N;i++){


	}
	int get(int l,int r){
	}
}

int main(){
	int N,Q;
	cin>>N>>Q;
	vector<int> P(N);
	for(int i=0;i<N;i++)cin>>P[i];
	LIS lis(P);
	for(;Q--;){
		int l,r;
		cin>>l>>r;
		cout<<lis.get(l,r)<<endl;
	}
}
