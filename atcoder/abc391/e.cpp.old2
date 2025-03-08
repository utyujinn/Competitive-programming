#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	int N=1;
	for(int i=0;i<n;i++){
		N*=3;
	}
	vector<vector<vector<int>>> list(n+1,vector<vector<int>>(N, vector<int>(2,0)));
	for(int i=0;i<N;i++){
		char a;
		cin>>a;
		list[0][i][!(a-'0')]=1;
	}
	for(int i=1;i<n+1;i++){
		for(int j=0;j<N/3;j++){
			int min1=4,min2=4;
			for(int k=0;k<3;k++){
				if(min1>list[i-1][j*3+k][0]){
					min2=min1;
					min1=list[i-1][j*3+k][0];
				}else if(min2>list[i-1][j*3+k][0]){
					min2=list[i-1][j*3+k][0];
				}
			}
			list[i][j][0]=min1+min2;
			min1=4,min2=4;
			for(int k=0;k<3;k++){
				if(min1>list[i-1][j*3+k][1]){
					min2=min1;
					min1=list[i-1][j*3+k][1];
				}else if(min2>list[i-1][j*3+k][1]){
					min2=list[i-1][j*3+k][1];
				}
			}
			list[i][j][1]=min1+min2;
		}
		N/=3;
	}
	if(list[n][0][0]==0)cout << list[n][0][1] << endl;
	else cout << list[n][0][0] << endl;
}
