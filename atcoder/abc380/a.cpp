#include<iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	int list[10];
	for(int i=0;i<10;i++)list[i]=0;
	for(int i=0;i<6;i++){
		list[N%10-1]++;
		N/=10;
	}
	if(list[0]==1 && list[1]==2 && list[2]==3){
		cout<<"Yes"<<endl;
	}else cout<<"No"<<endl;
		

}
