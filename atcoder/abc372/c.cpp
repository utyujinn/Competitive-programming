#include<iostream>
using namespace std;
int N,Q;

int main(){
	cin>>N>>Q;
	string S;cin>>S;
	int ans=0;
	for(int i=2;i<N;i++){
		if(S[i-2]=='A'&&S[i-1]=='B'&&S[i]=='C')ans++;
	}
	for(;Q--;){
		int x;
		char c;
		cin>>x>>c;
		x--;
		for(int i=0;i<=2;i++){
			if(x+i-2>=0&&x+i<N){
				if(S[x-2+i]=='A'&&S[x-1+i]=='B'&&S[x+i]=='C')ans--;
			}
		}
		S[x]=c;
		for(int i=0;i<=2;i++){
			if(x+i-2>=0&&x+i<N){
				if(S[x-2+i]=='A'&&S[x-1+i]=='B'&&S[x+i]=='C')ans++;
			}
		}
		cout<<ans<<endl;
	}
}
