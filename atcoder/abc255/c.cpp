#include<iostream>
using namespace std;
int main(){
	long long x,a,d,n;
	cin >> x >> a >> d >> n;
	long long big = max(a+d*(n-1),a);
	long long small = min(a+d*(n-1),a);
	if(d == 0){
		cout << abs(x-a) << endl;
		return 0;
	}
	if(big < x)cout << x-big << endl;
	else if(small > x) cout << small-x << endl;
	else cout << min((x-small)%abs(d),abs(d)-abs(x-small)%abs(d)) << endl;
}

