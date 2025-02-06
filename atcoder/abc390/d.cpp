#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<unordered_set>
using namespace std;
int n;
long a[12];

vector<long> list;
long cnt = 0;

void dfs(int depth, long b[], int groups, long num){
	if(depth == n){
		list.push_back(num);
	}
	else{
		for(int i = 0; i < groups+1; i++){
			num ^= b[i];
			b[i] += a[depth];
			num ^= b[i];
			if(i<groups)dfs(depth+1, b, groups, num);
			else dfs(depth+1, b, groups+1, num);
			num ^= b[i];
			b[i] -= a[depth];
			num ^= b[i];
		}
	}
}

int main(){
	cin >> n;
	for(int i= 0; i < n; i++){
		cin >> a[i];
	}
	long b[12];
	dfs(0,b,0,0);
	sort(list.begin(), list.end());
	list.erase(unique(list.begin(), list.end()), list.end());
	cout << list.size() << endl;
}
