#include<iostream>
#include<vector>
using namespace std;
vector<int> ldp[26],rdp[26];

int main(void){
  string S;cin>>S;
	int N=S.size();
	for(int i=0;i<26;i++){
		ldp[i].assign(N,0);
		rdp[i].assign(N,0);
	}
	ldp[S[0]-'A'][0]++;
	rdp[S[N-1]-'A'][N-1]++;
	for(int i=1;i<N;i++){
		for(int j=0;j<26;j++){
			ldp[j][i]=ldp[j][i-1];
		}
		ldp[S[i]-'A'][i]++;
	}
	for(int i=N-2;i>=0;i--){
		for(int j=0;j<26;j++){
			rdp[j][i]=rdp[j][i+1];
		}
		rdp[S[i]-'A'][i]++;
	}
	long ans=0;
	for(int i=1;i<N-1;i++){
		for(int j=0;j<26;j++){
			ans+=(long)ldp[j][i-1]*rdp[j][i+1];
		}
	}
	cout<<ans<<endl;
}
