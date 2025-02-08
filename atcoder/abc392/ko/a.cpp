#include<iostream>
#include<cassert>
#include<algorithm>
#include<vector>
using namespace std;
int N,M;
int A[2<<17],B[2<<17];
vector<pair<int,int> >G[2<<17];
bool vis[2<<17];
bool used[2<<17];
vector<int> ch;
void dfs(int u)
{
	vis[u]=true;
	for(auto[i,v]:G[u])
	{
		if(!vis[v])
		{
			used[i]=true;
			dfs(v);
		}
		else if(!used[i])
		{
			ch.push_back(i);
			used[i]=true;
		}
	}
}
int main(){
	cin>>N>>M;
	for(int i=0;i<M;i++)
	{
		cin>>A[i]>>B[i];
		A[i]--,B[i]--;
		G[A[i]].push_back(make_pair(i,B[i]));
		G[B[i]].push_back(make_pair(i,A[i]));
	}
	vector<pair<int,vector<int> > > PE;
	vector<vector<int>> E;
	for(int i=0;i<N;i++)if(!vis[i])
	{
		dfs(i);
		PE.push_back(make_pair(i,ch));
		ch.clear();
	}
	vector<pair<int,int> >ans;
	sort(PE.begin(),PE.end(),[](const pair<int,vector<int> >&l,const pair<int,vector<int> >&r){
			return l.second.size()>r.second.size();
		});
	for(int i=0;i<PE.size();i++){
		if(i>0){
			assert(!ch.empty());
			ans.push_back(make_pair(ch.back(),PE[i].first));
			ch.pop_back();
		}
		for(int j:PE[i].second)ch.push_back(j);
	}
	cout<<ans.size()<<endl;
	for(auto[i,v]:ans){
		cout<<i+1<<" "<<A[i]+1<<" "<<v+1<<endl;
	}
}

