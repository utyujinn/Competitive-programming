#include<iostream>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<tuple<int,int,int>> list(m);
	for(int i = 0;i  < m; i++){
		char a;
		cin >> x[i] >> y[i] >> a;
		if(a=='B')list[i] = {x[i], y[i], 0};
		else list[i] = {x[i], y[i], 1};
	}
	sort(list.begin(), list.end());
	for(int i = 0; i < m; i++){

		
		
