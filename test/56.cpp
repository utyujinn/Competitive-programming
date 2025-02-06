#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct edge{
	int to;
	int dist;
};

int main(){
	int v,e,r;
	cin >> v >> e >> r;
	vector<long> s(e),t(e),d(e);
	vector<long> dist(v, 1LL<<60);
	vector<vector<pair<long,long>>> G(v, vector<pair<long,long>>(0));
	edge E;
	for(int i = 0; i < e; i++){
		cin >> s[i] >> t[i] >> d[i];
		G[s[i]].emplace_back(t[i], d[i]);
	}
	priority_queue<pair<long,long>, vector<pair<long,long>>, greater<>> pq;
	pq.emplace(0,r);
	dist[r] = 0;
	while(!pq.empty()){
		pair<long,long> c = pq.top();
		pq.pop();
		if(dist[c.second]<c.first)continue;
		for(auto n: G[c.second]){
			int tmp = c.first + n.second;
			if(dist[n.first] > c.first + n.second){
				dist[n.first] = c.first + n.second;
				pq.emplace(c.first+n.second, n.first);
			}
		}
	}
	for(int i = 0; i < v; i++){
		if(dist[i] != 1LL<<60)cout << dist[i] << endl;
		else cout << "INF" << endl;
	}
}
