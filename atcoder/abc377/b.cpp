#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<string> S(8);
	for(int i=0;i<8;i++)cin>>S[i];
	vector<string> T=S;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(S[i][j]=='#'){
				for(int k=0;k<8;k++){
					T[i][k]='#';
					T[k][j]='#';
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(T[i][j]=='.'){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
