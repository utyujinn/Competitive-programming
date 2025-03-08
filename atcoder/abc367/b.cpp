#include<iostream>
using namespace std;

int main(){
	string x;
	cin>>x;
	int id=x.size()-1;
	while(x[id]=='0')id--;
	if(id==x.size()-4){
		for(int i=0;i<x.size()-4;i++){
			cout<<x[i];
		}
	}else{
		for(int i=0;i<id+1;i++){
			cout<<x[i];
		}
	}
	cout<<endl;
}
