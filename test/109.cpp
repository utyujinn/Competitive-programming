#include<iostream>
#include<vector>
using namespace std;

vector<vector<long>> matmul(vector<vector<long>> mat1, vector<vector<long>> mat2,int mod){
	vector res(mat1.size(), vector<long>(mat1.size(), 0));
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				res[i][j] = res[i][j] + mat1[i][k]*mat2[k][j];
			}
			res[i][j] %= mod;
		}
	}
	return res;
}

vector<vector<long>> matpow(vector<vector<long>> mat, int n, int mod){
	vector res(mat.size(), vector<long>(mat.size(), 0));
	for(int i = 0; i < mat.size(); i++){
		res[i][i] = 1;
	}
	for(int i = 0; i < 30; i++){
		if(n & (1<<i)){
			res = matmul(mat, res, mod);
		}
		mat = matmul(mat, mat, mod);
	}
	return res;
}

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<long>> mat = {{0,1}, {1,1}};
	vector<vector<long>> mat2 = matpow(mat, n-2, m);
	cout << mat2[1][1] << endl;
}
