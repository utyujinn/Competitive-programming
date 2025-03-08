#include<iostream>
using namespace std;

int main(){
	int N;cin>>N;
	long T=0;
	for(;N--;){
		int H;
		cin>>H;
		while(T%3!=0&&H>0){
			if(T%3==1){
				T++;
				H--;
			}
			else{
				T++;
				H-=3;
			}
		}
		if(H>0)T+=(H/5*3+((H%5>=3)?3:H%5));
	}
	cout<<T<<endl;
}
