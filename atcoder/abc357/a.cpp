#include<iostream>
using namespace std;

int main(){
	int N,M;
	cin>>N>>M;
	int cnt=0;
	for(;N--;){
		int H;cin>>H;
		if(M>=H){
			cnt++;
			M-=H;
		}else break;
	}
	cout<<cnt<<endl;
}
