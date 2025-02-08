#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int mod=998244353;

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

	long det() const {
		T det=1;
		int line=0;
		for(int col=0;col<n;col++){
			int pivot=col;
			while(pivot<n&&data[pivot][col]==0){
				pivot++;
			}
			if(pivot>=rows)continue;
			swap(data[line],data[pivot]);
			if(line!=pivot)
				det*=-1;
			det*=data[line][col];
			for(int j=line+1;j<rows;j++){
				for(int k=0;k<rows;k++){
					data[j]-=data[j][col]*data[line];
				}
			}
			line++;
		}
		return det*(line==n);
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
	long N;
	cin>>N;
	Matrix A(N,N);
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)cin>>A[i][j];
	cout<<A.det()<<endl;
}
