#include<iostream>
using namespace std;

int main(){
	string d; cin>>d;
	for(char&c:d){
		if(c=='N')c='S';
		else if(c=='S')c='N';
		else if(c=='W')c='E';
		else c='W';
	}
	cout << d << endl;
}
