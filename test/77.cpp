#include<iostream>
#include<vector>
using namespace std;
int main(){
	long n,m;
	cin >> n >> m;
	vector<long> dist(n-1);
	vector<long> sum(n);
	sum[0] = 0;

	for(long i = 0; i < n-1; i++){
		cin >> dist[i];
		sum[i+1] = sum[i] + dist[i];
	}
	long cur = 0;
	long prev = 0;
	long ans = 0;
	for(int i = 0; i < m; i++){
		int move;
		cin >> move;
		cur += move;
		ans += abs(sum[cur] - sum[prev]);
		ans %= 100000;
		prev = cur;
	}
	cout << ans << endl;
}
