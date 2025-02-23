#include<iostream>
using namespace std;

int main(){
	string S;
	cin>>S;
	int prev=0;
	for(int i=1;i<S.size();i++){
		if(S[i]=='|'){
			cout<<i-prev-1<<" ";
			prev = i;
		}
	}
	cout<<endl;
}
