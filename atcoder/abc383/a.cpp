#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int ct = 0;
	int t,v;
	int ans = 0;
	for(;n--;){
    cin >> t >> v;
		while(ct < t){
			ct++;
			if(ans > 0)ans--;
		}
		ans += v;
	}
	cout << ans << endl;
}
