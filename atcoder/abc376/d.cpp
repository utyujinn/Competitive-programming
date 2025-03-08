#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int N,M;
vector<int> G[2<<17];
bool seen[2<<17];
int ans=~0U>>1;

int main(){
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		G[a].push_back(b);
	}
	queue<pair<int,int>> q;
	pair<int,int> tmp=make_pair(0,0);
	q.push(tmp);
	while(!q.empty()){
		auto c=q.front();
		seen[c.first]=true;
		q.pop();
		for(int n:G[c.first]){
			if(n==0){
				ans=min(ans,c.second+1);
			}
			if(!seen[n]){
				pair<int,int> tmp=make_pair(n,c.second+1);
				q.push(tmp);
			}
		}
	}
	if(ans==~0U>>1)cout<<-1<<endl;
	else cout<<ans<<endl;
}
