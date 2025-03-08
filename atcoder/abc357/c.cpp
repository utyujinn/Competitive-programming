#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

vector<vector<char>> car(int N){
	if(N==0){
		vector<vector<char>> A(1,vector<char>(1,'#'));
		return A;
	}else{
		vector<vector<char>> A(pow(3,N),vector<char>(pow(3,N)));
		auto B=car(N-1);
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				for(int k=0;k<pow(3,N-1);k++){
					for(int l=0;l<pow(3,N-1);l++){
						A[k+i*pow(3,N-1)][l+j*pow(3,N-1)]=B[k][l];
					}
				}
			}
		}
		for(int i=pow(3,N-1);i<pow(3,N-1)*2;i++){
			for(int j=pow(3,N-1);j<pow(3,N-1)*2;j++){
				A[i][j]='.';
			}
		}
		return A;
	}
}

int main(){
	int N;cin>>N;
	auto A=car(N);
	for(int i=0;i<A.size();i++){
		for(int j=0;j<A[0].size();j++){
			cout<<A[i][j];
		}cout<<endl;
	}
}
