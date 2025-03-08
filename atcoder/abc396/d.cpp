#include<iostream>
#include<vector>
using namespace std;
unsigned long ans=~0ULL>>1;
vector<pair<int,unsigned long>> G[10];
bool seen[10];
unsigned long cnt=0;
int N,M;

void dfs(int c){
  if(c==N-1){
    ans=min(ans,cnt);
  }
  for(auto[n,w]:G[c]){
    if(!seen[n]){
      seen[n]=true;
      cnt^=w;
      dfs(n);
      cnt^=w;
      seen[n]=false;
    }
  }
}


int main(){
  cin>>N>>M;
  for(int i=0;i<M;i++){
    int u,v;
    unsigned long w;
    cin>>u>>v>>w;
    u--,v--;
    G[u].emplace_back(v,w);
    G[v].emplace_back(u,w);
  }
  seen[0]=true;
  dfs(0);
  cout<<ans<<endl;
}
