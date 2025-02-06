#include<iostream>
using namespace std;

int main(){
	int n,r;
	cin >> n >> r;
	int d,a;
	for(;n--;){
		cin >> d >> a;
		d--;
		if(d && r >=1200 && r < 2400){
			r += a;
		}else if(!d && r >=1600 && r < 2800){
			r += a;
		}
	}
	cout << r << endl;

}
