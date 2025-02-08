#include<iostream>
#include<vector>
using namespace std;

template<typename T>
void printmat(vector<vector<T>> &A){
	int n=A.size();
	cout<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}

template<typename T>
vector<vector<T> > matmul(vector<vector<T> > &A, vector<vector<T> > &B){
	int n=A.size();
	vector<vector<T>> R(n,vector<T>(n));
	for(int i=0;i<n;i++)for(int j=0;j<n;j++){
		for(int k=0;k<n;k++)R[i][j]^=A[i][k]&B[k][j];
	}
	return R;
}

template<typename T>
vector<vector<T> > matpow(vector<vector<T>> &A,int n){
	int s=A.size();
	vector<vector<T>> R(s,vector<T>(s));
	for(int i=0;i<s;i++)R[i][i]=~0U;
	vector<vector<T>> TMP=A;
	while(n!=0){
		if(n%2){
			R=matmul(R,TMP);
		}
		TMP=matmul(TMP,TMP);
		n/=2;
	}
	return R;
}

template<typename T>
vector<T> vecmatmul(vector<T> &A, vector<vector<T> > &B){
	int n=A.size();
	vector<T> R(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)R[i]^=A[j]&B[j][i];
	}
	return R;
}

int main(){
	int K,M;
	cin>>K>>M;
	vector<unsigned int> A(K);
	vector<unsigned int> C(K);
	for(int i=0;i<K;i++)cin>>A[i];
	for(int i=0;i<K;i++)cin>>C[i];
	vector<vector<unsigned int> > C2(K,vector<unsigned int>(K));
	for(int i=0;i<K-1;i++){
		C2[i+1][i]=~0U;
	}
	for(int i=0;i<K;i++){
		C2[K-i-1][K-1]=C[i];
	}
	C2=matpow(C2,M-1);
	A=vecmatmul(A,C2);
	cout<<A[0]<<endl;
}
