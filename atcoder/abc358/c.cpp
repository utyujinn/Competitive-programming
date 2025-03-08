#include<iostream>
#include<vector>
using namespace std;
string S[10];

int main(){
	int N,M;
	cin>>N>>M;
	int ans=10;
	for(int i=0;i<N;i++)cin>>S[i];
	for(int i=0;i<1<<N;i++){
		vector<bool> list(M);
		int cnt=0;
		for(int j=0;j<N;j++){
			if(i&(1<<j)){
				cnt++;
				for(int k=0;k<M;k++){
					if(S[j][k]=='o')list[k]=true;
				}
			}
		}
		bool flag=true;
		for(int k=0;k<M;k++){
			if(!list[k]){
				flag=false;
			}
		}
		if(flag)ans=min(ans,cnt);
	}
	cout<<ans<<endl;
}
