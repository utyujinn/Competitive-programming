#include<iostream>
#include<vector>
using namespace std;
int N,Q;

template<typename T>
struct SRS{
	int N;
	vector<T> S;
	SRS(vector<T> &A){
		N=A.size();
		S.resize(N+1);
		S[0]=0;
		for(int i=0;i<N;i++){
			S[i+1]=S[i]+A[i];
		}
	}
	T get(int l,int r){
		return S[r]-S[l];
	}
};

int main(){
	cin>>N>>Q;
	vector<long> A(N);
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	SRS srs(A);
	for(;Q--;){
		int l,r;
		cin>>l>>r;
		cout<<srs.get(l,r)<<endl;
	}
}
