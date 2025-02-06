#include<iostream>
#include<vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	while(n!=0){
		vector<int> list(86401);
		for(;n--;){
			string s,t;
			cin >> s >> t;
			int start = (((s[0]-'0')*10+(s[1]-'0'))*60 + (s[3]-'0')*10+(s[4]-'0'))*60 + (s[6]-'0')*10 + s[7]-'0';
			int end = (((t[0]-'0')*10+(t[1]-'0'))*60 + (t[3]-'0')*10+(t[4]-'0'))*60 + (t[6]-'0')*10 + t[7]-'0';
			list[start]++;
			list[end]--;
		}
		int ans = 0;
		int cur = 0;
		for(int i = 0; i < 86401; i++){
			cur+=list[i];
			ans = ans<cur?cur:ans;
		}
		cout << ans << endl;
		cin >> n;
	}
}

