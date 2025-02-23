#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N,X,Y;
int ans[2<<10];
vector<int> G[2<<10];

void wfs(int i,int depth){
	vector<bool> seen(2<<10);
	seen[i]=true;
	queue<pair<int,int>> q;
	q.push(make_pair(i,0));
	while(!q.empty()){
		auto c=q.front();
		q.pop();
		for(auto n:G[c.first]){
			if(!seen[n]){
				q.push(make_pair(n,c.second+1));
				ans[c.second+1]++;
				seen[n]=true;
			}
		}
	}
}

int main(){
	cin>>N>>X>>Y;
	for(int i=0;i<N-1;i++){
		G[i].push_back(i+1);
		G[i+1].push_back(i);
	}
	X--,Y--;
	G[X].push_back(Y);
	G[Y].push_back(X);
	for(int i=0;i<N;i++){
		wfs(i,0);
	}
	for(int i=1;i<N;i++){
		cout<<ans[i]/2<<endl;
	}
}
