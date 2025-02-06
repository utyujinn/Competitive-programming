#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> list(200001, -1);
	int index = 200000;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		while(index >= a){
			list[index] = i+1;
			index--;
		}
	}
	for(int i = 0; i < m; i++){
		int b;
		cin >> b;
		cout << list[b] << endl;
	}
}
