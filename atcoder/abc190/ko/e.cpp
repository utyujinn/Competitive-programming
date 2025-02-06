#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main(){
	int n,m;
	vector<int> G[1<<17];
	for(int i = 0; i < m; i++){
		int a,b;
		cin >> a >> b;
		a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int k;
	cin >> k;
	for(int i =0; i<k ; i++){

