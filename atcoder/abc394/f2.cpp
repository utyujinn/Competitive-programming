#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int> G[2<<17];
bool seen[2<<17];
int dp[2<<17];
int ans=0;

int wfs(int c,int p,int depth){
	seen[c]=true;
	if(G[c].size()<4){
		return 0;
	}else{
		int ret=1;
		vector<int> list;
		vector<int> tmp;
		for(int n:G[c])if(n!=p){
			int a=wfs(n,c,depth+1);
			tmp.push_back(a);
			list.push_back(a);
		}
		sort(list.rbegin(),list.rend());
		for(int i=0;i<(depth==0?4:3);i++){
			ret+=list[i];
		}
		int id=0;
		for(int n:G[c])if(n!=p){
			dp[n]=ret-tmp[id];
			id++;
		}
		return ret;
	}
}

int wfs2(int c,int p,int depth){
	if(G[c].size()<4){
		return 0;
	}else{
		int ret=1;
		vector<int> list;
		for(int n:G[c])if(n!=p){
			int tmp=wfs(n,c,depth+1);
			list.push_back(tmp);
		}
		sort(list.rbegin(),list.rend());
		for(int i=0;i<(depth==0?4:3);i++){
			ret+=list[i];
		}
		list.push_back(dp[c]);
		sort(list.rbegin(),list.rend());
		int ret2=1;
		for(int i=0;i<4;i++){
			ret2+=list[i];
		}
		ans=max(ans,ret2);
		return ret;
	}
}

int main(){	
	cin>>N;
	for(int i=0;i<N-1;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=0;i<N;i++){
		if(!seen[i] && G[i].size()>=4){
			ans=max(ans,wfs(i,-1,0));
		}
	}
	for(int i=0;i<N;i++){
		seen[i]=false;
	}
	for(int i=0;i<N;i++){
		if(!seen[i] && G[i].size()>=4){
			ans=max(ans,wfs2(i,-1,0));
		}
	}
	if(N<=4)cout<<-1<<endl;
	else if(ans==0)cout<<-1<<endl;
	else cout<<3*ans+2<<endl;
}
