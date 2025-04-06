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
					result[i][j]%=998244353;
				}
			}
		}
		return result;
	}

	Matrix pow(long K) const{
		Matrix result(rows, rows);
		for(int i=0;i<rows;i++)result[i][i]=1;
		Matrix tmp(rows,rows);
		for(int i=0;i<rows;i++)for(int j=0;j<cols;j++)tmp[i][j]=data[i][j];
		while(K){
			if(K%2)result=result*tmp;
			tmp=tmp*tmp;
			K/=2;
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
long len=1e18;

int main(){
	Matrix A(5,5);
	B.print();
}

