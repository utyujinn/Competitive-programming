#include<iostream>
#include<map>
using namespace std;

int main(){
	map<char,int> list;
	for(int i=0;i<3;i++){
		char a;cin>>a;
		list[a]=i;
	}
	if(list['R']<list['M']){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
}
