#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	vector<int> a(5);
	for(int i = 0; i < 5; i++){
		cin >> a[i];
	}
	int cnt = 0;
	for(int i = 0; i < 4; i++){
		if(a[i] > a[i+1]){
			cnt++;
			int tmp = a[i];
			a[i] = a[i+1];
			a[i+1] = tmp;
		}
	}
	if(cnt==1)cout << "Yes" << endl;
	else cout << "No" << endl;
}
