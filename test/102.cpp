#include<iostream>
#include<map>
using namespace std;

int main(){
	int n;
	map<int,int> m;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		m[a[i]];
	}
	int index = 0;
	for(auto&x : m)x.second = index++;
	for(int i = 0; i < n; i++){
		cout << m[a[i]] << endl;
	}
}
