#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
	long n,m;
	cin >> n >> m;
	vector<long> p(n),s(0);
	for(int i = 0; i < n; i++)cin >> p[i];
	p.push_back(0);
	for(int i = 0; i < n+1; i++)for(int j = 0; j < n+1; j++)s.push_back(p[i]+p[j]);
	sort(s.begin(), s.end());
	long ans = 0;
	for(int i = 0; i < (n+1)*(n+1); i++){
		long low = 0, high = (n+1)*(n+1);
		while(high-low>1){
			long middle = (low + high)/2;
			if(s[middle] > m-s[i])high = middle;
			else low = middle;
		}
		if(s[i] + s[low] > m)continue;
		ans = ans < s[i] + s[low] ? s[i] + s[low] : ans;
	}
	cout << ans << endl;
}
