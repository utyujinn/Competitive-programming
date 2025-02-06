#include<iostream>
#include<vector>
using namespace std;

int main(){
	long n,m,a,b;
	cin >> n >> m >> a >> b;
	long l, r;
	long al = 1, ar = 1;
	for(int i = 0; i < m; i++){
		cin >> l >> r;
		long prog = l-1-ar;
		long x = 1 + prog / b;
		long eb = (x-1)*a + ar;

		long prog2 = l-1-al;
		long x2 = 1 + prog2 / b;
		long eb2 = (x2-1)*a + al;

		




}
