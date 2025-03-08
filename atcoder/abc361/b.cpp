#include<iostream>
using namespace std;
int a[2][6];
int b[2][6];

int main(){
	for(int i=0;i<2;i++)for(int j=0;j<3;j++){
		cin>>a[i][j];
		a[i][j+3]=a[i][j];
	}
	for(int i=0;i<2;i++)for(int j=0;j<3;j++){
		cin>>b[i][j];
		b[i][j+3]=b[i][j];
	}
	for(int i=0;i<3;i++){
		if(a[1][0+i]<=b[0][0+i]||a[0][0+i]>=b[1][0+i]||a[1][1+i]<=b[0][1+i]||a[0][1+i]>=b[1][1+i]){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
}
