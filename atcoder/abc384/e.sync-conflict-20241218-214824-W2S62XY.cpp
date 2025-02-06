#include<iostream>
#include<tuple>
#include<queue>
using namespace std;

int main(){
	int h,w,x;
	cin >> h >> w >> x;
	int p,q;
	cin >> p >> q;
	vector<vector<long>> s(h+2,vector<long>(w+2));
	vector<vector<bool>> seen(h+2,vector<bool>(w+2, false));
	for(int i = 0; i < h; i++)for(int j = 0; j < w; j++)cin >> s[i+1][j+1];
	for(int i = 0; i < h; i++)s[i][0] = s[i][w+1] = 1LL<<60;
	for(int i = 0; i < w; i++)s[0][i] = s[h+1][i] = 1LL<<60;
	priority_queue<tuple<long, long, long>, vector<tuple<long, long, long>>, greater<>> pq;
	pq.emplace(s[p][q], p, q);
	seen[p][q] = true;
	long ans = s[p][q];
	cout << ans << endl;
	while(!pq.empty()){
		auto [tmp, x, y] = pq.top();
		cout << tmp << endl;
		pq.pop();
		if(tmp*x < ans){
			ans += tmp;
			for(int i = 0; i < 4; i++){
				if(i==0 && !seen[x][y-1] && y-1 >= 1){
					seen[x][y-1] = true;
					pq.emplace(s[x][y-1], x, y-1);
				}
				if(i==1 && !seen[x+1][y] && x+1 <= w){
					seen[x+1][y] = true;
					pq.emplace(s[x+1][y], x+1, y);
				}
				if(i==2 && !seen[x][y+1] && y+1 <= h){
					seen[x][y+1] = true;
					pq.emplace(s[x][y+1], x, y+1);
				}
				if(i==3 && !seen[x-1][y] && x-1 >= 1){
					seen[x-1][y] = true;
					pq.emplace(s[x-1][y], x-1, y);
				}
			}
		}
	}
	cout << ans << endl;
}
