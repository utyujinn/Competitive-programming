#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int t;
	cin >> t;
	for(;t--;){
		int n;
		cin >> n;
		vector<pair<int,int>> a(n);
		int sw = 0;
		for(int i = 0; i < n; i++){
			cin >> a[i].first;
		}
		for(int i = 0; i < n; i++){
			cin >> a[i].second;
		}
		for(int i = 0; i < n; i++){
			if(a[i].first < a[i].second){
				swap(a[i].first, a[i].second);
				sw++;
			}
		}
		int able = 4-(sw%4);
		int cnt = 0;
		sort(a.begin(), a.end());
		int flag = 1;
		for(int i = 1; i < n; i++){
			if(a[i].second > a[i-1].second){}
			else{
				flag = 0;
			}
			if(a[i-1].second < a[i].first)cnt++;
		}
		if(cnt < able){
			flag = 0;
		}
		if(flag){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
}
