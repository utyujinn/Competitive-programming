#include<iostream>
#include<vector>
using namespace std;

long n,m,u;

void dfs(int cnt, vector<int> list){
	for(int i = 0; i+cnt <= u; i++){
		list.push_back(i);
		cnt+=i;
		if(list.size()==n){
			int sum = 0;
			for(int j = 0; j < n; j++){
				sum += list[j];
				cout << 1+sum+10*j << " ";
			}
			cout << endl;
		}else{
			dfs(cnt,list);
		}
		list.pop_back();
		cnt-=i;
	}
}

long fab(long n){
	if(n==0)return 1;
	else return fab(n-1)*n;
}
long c(long n, long k){
	return (fab(n)/fab(k))/fab(n-k);
}
long comb(int n, int k){
	if(k > n) return 0;
	if(k > n-k) k = n-k;
	long res = 1;
	for(int i = 0; i < k; i++){
		res = res * (n-i) / (i+1);
	}
	return res;
}

int main(){
	cin >> n >> m;
	u = m-10*n+9;
	vector<int> list(0);
	cout << comb(n+u,u) << endl;
	dfs(0,list);
}
