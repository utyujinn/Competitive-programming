#include<iostream>
#include<vector>
using namespace std;
vector<pair<int,int>> G[2<<17];
bool seen[2<<17];
int A[2<<17];
int N,M;
int ans=0;

void dfs(int c){
  seen[c]=true;
  long cnt=0;
  bool flag=true;
  for(auto[n,w]:G[c]){
    if(!seen[n]){
      A[n]=w^A[c];
      dfs(n);
    }else{
      if(A[n]^A[c]!=w){
        ans=-1;
        return;
      }
    }
  }
}

int main(){
  cin>>N>>M;
  for(int i=0;i<M;i++){
    int x,y,z;
    cin>>x>>y>>z;
    x--,y--;
    if(x==y&&z!=0){
      cout<<-1<<endl;
      return 0;
    }
    if(x!=y){
      G[x].emplace_back(y,z);
      G[y].emplace_back(x,z);
    }
  }
  int mdeg=0;
  int mv = 0;
  for(int i=0;i<N;i++){
    if(mdeg<G[i].size()){
      mdeg=G[i].size();
      mv=i;
    }
  }
  long cnt=0;
  for(auto [n,w]:G[mv]){
    cnt&=w;
  }
  A[mv]=cnt;
  dfs(mv);
  if(ans==-1){
    cout<<-1<<endl;
    return 0;
  }
  for(int i=0;i<N;i++){
    cout<<A[i]<<" ";
  }
  cout<<endl;
}
