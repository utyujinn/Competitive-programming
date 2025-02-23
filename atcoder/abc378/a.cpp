#include<iostream>
#include<map>
using namespace std;

int main(){
	map<int,int> A;
	for(int i=0;i<4;i++){
		int a;
		cin>>a;
		A[a]++;
	}
	int ans=0;
	for(auto a:A){
		ans+=a.second/2;
	}
	cout<<ans<<endl;
}
