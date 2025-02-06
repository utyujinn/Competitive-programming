#include<iostream>
using namespace std;

int main(){
	long long n;
	cin >> n;
	n*=2;
	int ans = 0;
	for(long long i = 1; i*i < n; i++)if(n%i==0){
		long long tmp = n/i - i + 1;
		if(tmp%2==0)ans++;
	}
	cout << ans*2 << endl;
}

