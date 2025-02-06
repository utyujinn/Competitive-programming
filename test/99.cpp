#include<iostream>

using namespace std;

int main(){
	int m;
	cin >> m;
	long sum = 0;
	long dig = 0;
	for(int i = 0; i < m; i++){
		long d,c;
		cin >> d >> c;
		sum += d*c;
		dig += c;
	}
	cout << (sum-1)/9 + dig - 1 << endl;
}
