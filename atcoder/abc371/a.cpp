#include<iostream>
using namespace std;

int main(){
	char ab,ac,bc;
	cin>>ab>>ac>>bc;
	if(ab=='<'){
		if(bc=='<'){
			cout<<'B'<<endl;
		}else if(bc=='>'){
			if(ac=='>'){
				cout<<'A'<<endl;
			}
			else{
				cout<<'C'<<endl;
			}
		}
	}else if(ab=='>'){
		if(ac=='>'){
			if(bc=='<'){
				cout<<'C'<<endl;
			}
			else{
				cout<<'B'<<endl;
			}
		}
		else if(ac=='<'){
			cout<<'A'<<endl;
		}
	}
}
