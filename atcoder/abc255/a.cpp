#include<iostream>
using namespace std;

int main(){
	int r,c;
	cin >> r >> c;
	int a[2][2];
	cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1];
	r--,c--;
	cout << a[r][c] << endl;
}
