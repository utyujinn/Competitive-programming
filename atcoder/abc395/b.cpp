#include<iostream>
using namespace std;
char mp[50][50];

int main(){
	int N;cin>>N;
	for(int i=0;i<N/2+1;i++){
		for(int j=i;j<N-i;j++){
			for(int k=i;k<N-i;k++){
				if(i%2==0)mp[j][k]='#';
				else mp[j][k]='.';
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<mp[i][j];
		}
		cout<<endl;
	}
}
