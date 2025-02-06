#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

int main(){
	long n,m;
	cin >> n >> m;
	vector<int> p(n);
	for(int i = 0; i < n; i++){
		cin >> p[i] ;
	}
	sort(p.begin(), p.end());

	long ok=0,ng=1e18;
	while(ok-ng>1){
		long mid = (ok+ng)/2;
		long tmp,cnt=0;
		long money = 0;
		vector<long> list(n);
		priority_queue<pair<long,long>,vector<pair<long,long>>,greater<>> pq;
		for(int i = 0; i < n; i++){
			tmp = floor(sqrt((m/n)/p[i]));
			cnt += tmp;
			list[i] = tmp;
			pq.emplace(p[i]*(2*tmp+1), i);
			money += p[i]*(2*tmp-1);
		}
		int flag = 0;
		while(money <= m && cnt <= mid){
			if(cnt >= mid){
				flag = 1;
				break;
			}
			auto cnt = pq.top();
			pq.pop();
			money += cnt.first;
			pq.emplace(cnt.first + p[cnt.second]*2, cnt.second);
		}
		if(flag) ok = mid;
		else ng = mid;
	}
	cout << ok << endl;
}
