#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> h(n);
	for(int i = 0; i < n; i++){
		cin >> h[i];
	}
	int ans = 1;
	for(int i = 0; i < n; i++){
		set<int> st;
		for(int j = i+1; j < n; j++){
			if(h[i] == h[j]){
				st.insert(j-i);
			}
		}
		for(int j: st){
			int cnt = 1;
			while(true){
				if(!st.count(j*cnt))break;
				cnt++;
			}
			ans = cnt>ans?cnt:ans;
			if(ans == 3000) break;
		}
	}
	cout << ans << endl;
}
