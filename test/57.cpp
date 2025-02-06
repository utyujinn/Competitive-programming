#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	vector<vector<pair<int, int>>> G(n);
	for(;k--;){
		int q;
		cin >> q;
		if(q==0){
				int a,b;
				cin >> a >> b;
				a--;b--;
				vector<int> dist(n, 1<<30);
				dist[a] = 0;
				priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
				pq.emplace(0,a);
				while(!pq.empty()){
					pair<int,int> cur = pq.top();
					pq.pop();
					int cdist = cur.first;
					int cv = cur.second;
					if(cv == b)break;
					if(cdist > dist[cv])continue;
					for(auto next: G[cv]){
						int ndist = next.first;
						int vnext = next.second;
						if(dist[vnext] > ndist + cdist){
							dist[vnext] = ndist + cdist;
							pq.emplace(dist[vnext], vnext);
						}
					}
				}
				if(dist[b] == 1<<30) cout << -1<< endl;
				else cout << dist[b] << endl;
		}else{
				int c,d,e;
				cin >> c >> d >> e;
				c--;d--;
				G[c].emplace_back(e,d);
				G[d].emplace_back(e,c);
		}
	}
}
