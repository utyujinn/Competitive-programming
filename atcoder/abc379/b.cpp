#include<iostream>
using namespace std;

int main(){

	int N,K;
	cin>>N>>K;
	int prev=-1;
	string s;
	cin>>s;
	int ans=0;
	for(int i=0;i<N;i++){
		if(s[i]=='X'){
			ans+=(i-prev-1)/K;
			prev=i;
		}
	}
	ans+=(N-prev-1)/K;
	cout<<ans<<endl;
}
