#include<iostream>
using namespace std;

int main(){
	int x,y;
	cin >> x >> y;
	cout << x*y << " " << x*y << endl;
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			if(j==y-1 && i == x-1){
				cout << i+x*j+1 << " " << i+x*j+1-x+1 << endl;
			}else if(j==y-1){
				cout << i+x*j+1 << " " << i+x*j+1+1 << endl;
			}else{
				cout << i+x*j+1 << " " << i+x*(j+1)+1 << endl;
			}
		}
	}
}
