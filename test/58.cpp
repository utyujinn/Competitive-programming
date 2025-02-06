#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
	long n,m,k,s;
	cin >> n >> m >> k >> s;
	vector<vector<pair<long, long>>> G(n);
	long p,q;
	cin >> p >> q;
	vector<long> c(k);
	for(int i = 0; i < k; i++){
		cin >> c[i];
		c[i]--;
	}
	vector<long> x(m),y(m);
	for(int i = 0; i < m; i++){
		cin >> x[i] >> y[i];
		x[i]--;y[i]--;
		if(y[i] != n-1){
			G[x[i]].emplace_back(p, y[i]);
		}else{
			G[x[i]].emplace_back(0, y[i]);
		}
		if(x[i] != n-1){
			G[y[i]].emplace_back(p, x[i]);
		}else{
			G[y[i]].emplace_back(0, x[i]);
		}
	}
	for(int i = 0; i < k; i++){
		queue<long> Q;
		vector<long> area(n,-1);
		Q.push(c[i]);
		area[c[i]] = 0;
		while(!Q.empty()){
			long cnt = Q.front();
			Q.pop();
			if(area[cnt] > s)break;
			for(auto next: G[cnt]){
				if(area[next.second] == -1){
					area[next.second] = area[cnt] + 1;
					Q.emplace(next.second);
				}
				for(pair<long,long> &back: G[next.second]){
					if(back.second == cnt && back.second != n-1){
						if(area[cnt] == 0)back.first = 1LL<<60;
						else back.first = q;
						cout << next.second << " " << back.second << endl;
						break;
					}
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(auto cnt: G[i]){
			cout << "from: "<< i+1 << " to: " << cnt.second+1 << " dist" << cnt.first << endl;
		}
	}
	priority_queue<pair<long,long>, vector<pair<long,long>>, greater<>> pq;
	vector<long> dist(n, 1LL<<60);
	pq.emplace(0,0);
	dist[0] = 0;
	while(!pq.empty()){
		pair<long,long> cnt = pq.top();
		long dcnt = cnt.first;
		long vcnt = cnt.second;
		pq.pop();
		if(dist[vcnt] < dcnt)continue;
		for(auto next: G[vcnt]){
			long dnext = next.first;
			long vnext = next.second;
			if(dist[vnext] > dist[vcnt] + dnext){
				dist[vnext] = dist[vcnt] + dnext;
				pq.emplace(dist[vnext], vnext);
			}
		}
	}
	cout << dist[n-1] << endl;
}

