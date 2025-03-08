#include<iostream>
using namespace std;

int main(){
	int N,C;
	cin>>N>>C;
	int prev=-1000;
	int ans=0;
	for(int i=0;i<N;i++){
		int t;
		cin>>t;
		if(t-prev>=C){
			ans++;
			prev=t;
		}
	}
	cout<<ans<<endl;
}
