#include<iostream>
#include<vector>
using namespace std;
int main(){
	int t;
	cin >> t;
	for(;t--;){
		int n;
		cin >> n;
		vector<int> list(n);
		int prev;
		cin >> list[0];
		int flag = 1;
		for(int i = 1; i < n; i ++){
			cin >> list[i];
			int tmp = min(list[i-1],list[i]);
			list[i] -= tmp;
			list[i-1] -= tmp;
			if(list[i-1] > 0){
				flag = 0;
			}
		}
		if(flag){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
}
