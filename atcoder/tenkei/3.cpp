#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dfs(int idx, vector<vector<int>> G, vector<int> seen){
	int cnt = 1;
	int tmp = cnt;
	seen[idx] = 1;
	for(auto next: G[idx]){
		if(!seen[next])
			cnt = max(cnt,tmp+dfs(next, G, seen));
	}
	seen[idx] = 0;
	return cnt;
}

int main(){
	int n;
	cin >> n;
	vector<vector<int>> G(n);
	for(int i = 0; i < n-1; i++){
		int a,b;
		cin >> a >> b;
		a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int idx = 0;
	int num = 0;
	for(int i = 0; i < n; i++){
		num = max(num, int(G[i].size()));
		if(num == G[i].size())
			idx =	i; 
	}
	vector<int> seen(n, 0);
	seen[idx] = 1;
	vector<int> list(0);
	for(auto next: G[idx]){
		list.push_back(dfs(next,G,seen));
	}
	sort(list.rbegin(), list.rend());
	cout << list[0]+list[1]+1 << endl;
}
