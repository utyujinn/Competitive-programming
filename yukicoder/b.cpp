#include<iostream>
using namespace std;

int main(){
	int r;
	int x = 1e9/2;
	cout << x << endl;
	cin >> r;
	while(r==0){
		x /= 2;
		cout << x << endl;
		cin >> r;
	}
}
