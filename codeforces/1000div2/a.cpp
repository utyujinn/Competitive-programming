#include<iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(;t--;){
		int a,b;
		cin >> a >> b;
		if(a==b&&a==1)cout << 1 << endl;
		else{
			int ans = 0;
			if(a==1){
				ans++;
				a=2;
			}
			ans += b-a;
			cout << ans << endl;
		}
	}
}
