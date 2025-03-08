#include<iostream>
#include<algorithm>
using namespace std;
string S[100];
string T[100];

int main(){
	int N;cin>>N;
	int M=0;
	for(int i=0;i<N;i++){
		cin>>S[i];
		M=max(M,(int)S[i].size());
	}
	for(int i=0;i<N;i++){
		S[i].resize(M,'*');
	}
	for(int i=0;i<M;i++){
		T[i].resize(N,'*');
	}
	for(int i=0;i<M;i++){
		for(int j=N-1;j>=0;j--){
			T[i][j]=S[j][i];
		}
	}
	for(int i=0;i<M;i++){
		int idx=0;
		while(T[i][idx]=='*'){
			T[i][idx]=' ';
			idx++;
		}
		reverse(T[i].begin(),T[i].end());
		cout<<T[i]<<endl;
	}
}
