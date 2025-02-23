#include<iostream>
#include<vector>
using namespace std;

int main(){
	int N;
	cin>>N;
	string S;
	cin>>S;
	long cnt=0;
	for(long i=0;i<N;i++){
		cnt+=(S[i]-'0')*(i+1);
	}
	vector<long> ans(N);
	long up=0;
	for(long i=0;i<N;i++){
		ans[i]=(cnt+up)%10;
		up=(cnt+up)/10;
		cnt-=(S[N-i-1]-'0')*(N-i);
	}
	if(up)cout<<up;
	for(int i=N-1;i>=0;i--){
		cout<<ans[i];
	}
	cout<<endl;
}
