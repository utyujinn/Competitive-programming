#include<iostream>
#include<map>
using namespace std;

int main(){
	int N;
	cin>>N;
	map<int,int> A;
	for(int i=0;i<N;i++){
		int a;
		cin>>a;
		if(!A[a]){
			cout<<-1<<" ";
		}
		else{
			cout<<A[a]<<" ";
		}
		A[a]=i+1;
	}
	cout<<endl;
}
