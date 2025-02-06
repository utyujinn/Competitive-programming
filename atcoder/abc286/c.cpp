#include<iostream>
#include<vector>
using namespace std;

int main(){
	long long n,a,b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	long long ans = 1LL<<60;
	for(int i = 0; i < n; i++){
		long long diff = 0;
		for(int j = 0; j < n/2; j++){
			if(s[j] != s[n-j-1]){
				diff++;
			}
		}
		ans = (ans>a*i+diff*b)?a*i+diff*b:ans;
		char tmp = s[0];
		s.erase(s.begin());
		s+=tmp;
	}
	cout << ans << endl;
}
