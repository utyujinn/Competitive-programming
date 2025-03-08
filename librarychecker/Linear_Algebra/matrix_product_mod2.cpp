#include<iostream>
#include<vector>
using namespace std;

template<typename T>
struct Matrix {
	T rows;
	T cols;
	vector<vector<T> > data;

	Matrix(T r,T c):rows(r),cols(c),data(r,vector<T>(c)){}

	vector<T>& operator[](int index){
		return data[index];
	}
	const vector<T>& operator[](int index) const{
		return data[index];
	}

	Matrix operator*(const Matrix& other) const{
		Matrix result(rows, other.cols);
		for(int i=0;i<rows;i++){
			for(int j=0;j<other.cols;j++){
				for(int k=0;k<cols;k++){
					result[i][j]+=data[i][k]*other[k][j];
					result[i][j]%=2;
				}
			}
		}
		return result;
	}

	void print(){
		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				cout<<data[i][j]<<" ";
			}
			cout<<endl;
		}
	}
};

int main(){
	long N,M,K;
	cin>>N>>M>>K;
	Matrix A(N,M);
	Matrix B(M,K);
	for(int i=0;i<N;i++)for(int j=0;j<M;j++)cin>>A[i][j];
	for(int i=0;i<M;i++)for(int j=0;j<K;j++)cin>>B[i][j];
	auto C=A*B;
	C.print();
}
