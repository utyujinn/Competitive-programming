#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
using namespace std;
int main(){
	long h,w,X,p,q;
	cin >> h >> w >> X >> p >> q;
	p--,q--;
	vector<vector<long>> s(h, vector<long>(w));
	vector<vector<bool>> visited(h, vector<bool>(w,false));
	for(int i = 0; i < h ; i++)for(int j = 0; j < w; j++){
		cin >> s[i][j];
	}
	long ans = 0;
	priority_queue<tuple<long, long, long>, vector<tuple<long, long, long>>, greater<>> pq;
	visited[p][q] = true;
	pq.push({s[p][q], p, q});
	bool first = true;

	while(!pq.empty()){
		auto [st, x, y] = pq.top();
		pq.pop();
		if(st < (ans+X-1)/X || first){
			ans += st;
			if(first){
				first = false;
			}
			if(x > 0)
				if(!visited[x-1][y]){
					visited[x-1][y] = true;
					pq.push({s[x-1][y],x-1, y});
				}
			if(y > 0)
				if(!visited[x][y-1]){
					visited[x][y-1] = true;
					pq.push({s[x][y-1],x, y-1});
				}
			if(x < h-1)
				if(!visited[x+1][y]){
					visited[x+1][y] = true;
					pq.push({s[x+1][y],x+1, y});
				}
			if(y < w-1)
				if(!visited[x][y+1]){
					visited[x][y+1] = true;
					pq.push({s[x][y+1],x, y+1});
				}
		}
	}
	cout << ans << endl;
}
