#include<iostream>
using namespace std;

int main(){
	string S,T;cin>>S>>T;
	for(int w=1;w<S.size();w++){
		for(int j=0;j<w;j++){
			string U;
			int k=j;
			while(k<S.size()){
				U=U+S[k];
				k+=w;
			}
			if(U==T){
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	}
	cout<<"No"<<endl;
}
