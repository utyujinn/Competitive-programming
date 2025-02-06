#include<iostream>
#include<vector>
using namespace std;

void solve(){
	int n;
	cin >> n;
	int flag = 1;
	int ans = 0;
	int a;
	for(;n--;){
		cin >> a;
		if(a%2==0){
			if(flag){
				ans++;
				flag = 0;
			}
		}else{
			ans++;
		}
	}
	if(flag)cout << ans-1 << endl;
	else cout << ans << endl;
}

int main(){
	int t;
	cin >> t;
	for(;t--;)solve();
}
