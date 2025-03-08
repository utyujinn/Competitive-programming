#include<iostream>
using namespace std;
int S[101][101][101];

int main(){
	int N;cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<N;k++){
				int A;cin>>A;
				S[i+1][j+1][k+1]=A+S[i][j+1][k+1]+S[i+1][j][k+1]+S[i+1][j+1][k]-S[i][j][k+1]-S[i][j+1][k]-S[i+1][j][k]+S[i][j][k];
			}
		}
	}
	int Q;cin>>Q;
	for(;Q--;){
		int a,b,c,d,e,f;cin>>a>>d>>b>>e>>c>>f;
		cout<<S[d][e][f]-S[d][e][c-1]-S[d][b-1][f]-S[a-1][e][f]+S[a-1][b-1][f]+S[a-1][e][c-1]+S[d][b-1][c-1]-S[a-1][b-1][c-1]<<endl;
	}
}
