#include<iostream>
using namespace std;

int main(){
	int N,K,X;
	cin>>N>>K>>X;
	for(int i=0;i<N;i++){
		int a;
		cin>>a;
		cout<<a<<" ";
		if(i==K-1)cout<<X<<" ";
	}cout<<endl;
}
