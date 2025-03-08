#include<iostream>
using namespace std;
string A[4][3001];
string B[3001];

int main(void){
  int N;
  cin>>N;
	for(int i=1;i<=N;i++){
		cin>>A[0][i];
		A[0][i]="a"+A[0][i];
		B[i]=A[0][i];
	}
	for(int i=1;i<=3;i++){
		for(int j=0;j<=N;j++){
			A[i][j]=A[0][j];
		}
	}
  for(int i=1;i<=3;i++){
    for(int j=1;j<=N;j++){
      for(int k=1;k<=N;k++){
         A[i][j][N+1-k]=A[i-1][k][j];
      }
    }
  }
	for(int i=1;i<=N/2;i++){
		int s=i,t=N-i+1;
		for(int j=s;j<=t;j++){
			B[s][j]=A[i%4][s][j];
			B[t][j]=A[i%4][t][j];
			B[j][s]=A[i%4][j][s];
			B[j][t]=A[i%4][j][t];
		}
	}
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
        cout<<B[i][j];
    }
    cout << endl;
  }
  return 0;
}
