#include<iostream>
using namespace std;

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	if(c == 0){
		if(a > b){
			cout <<	"Takahashi" << endl;
		}
		else{
			cout << "Aoki" << endl;
		}
	}
	else{
		if(a >= b){
			cout <<	"Takahashi" << endl;
		}
		else{
			cout << "Aoki" << endl;
		}
	}

}
