#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int> A(26);
	for(int i=0;i<3;i++){
		char a;
		cin>>a;
		A[a-'A']++;
	}
	for(int i=0;i<3;i++){
		if(A[i]!=1){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
}
