#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int r;
	cin >> r;
	long ans = 0;
	long f = 0;
	long r2sq = 4*r*r;
	for(long i = 1; i < 2*r; i+=2){
		long tmp = floor(sqrt(r2sq-i*i));
		ans += (tmp+1)/2-1;
	}
	ans*=4;
	ans += 1;
	cout << ans << endl;
}
