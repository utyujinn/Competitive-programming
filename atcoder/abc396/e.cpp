#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int>> G[2<<17];
bool seen[2<<17];
bool seen2[2<<17];
int A[2<<17];
int N,M;
int ans;

int dfs(int c,vector<int> &list){
  for(auto[n,w]:G[c]){
    if(!seen[n]){
      seen[n]=true;
      A[n]=w^A[c];
      list.push_back(A[n]);
      int res=dfs(n,list);
      if(res==-1){
        return -1;
      }
    }else{
      if((A[n]^A[c])!=w){
        return -1;
      }
    }
  }
  return 0;
}

void dfs2(int c,int a){
  for(auto[n,w]:G[c]){
    if(!seen2[n]){
      seen2[n]=true;
      A[n]^=a;
      dfs2(n,a);
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
  for(int i=0;i<N;i++){
    sort(G[i].begin(),G[i].end());
    G[i].erase(unique(G[i].begin(),G[i].end()),G[i].end());
    for(int j=1;j<G[i].size();j++){
      if(G[i][j].first==G[i][j-1].first&&G[i][j].second!=G[i][j-1].second){
        cout<<-1<<endl;
        return 0;
      }
    }
  }
  for(int i=0;i<N;i++){
    if(!seen[i]){
      seen[i]=true;
      A[i]=0;
      vector<int> list;
      list.push_back(0);
      for(auto[to,c]:G[i]){
        if(!seen[to]){
          seen[to]=true;
          A[to]=c;
          list.push_back(A[to]);
          int res=dfs(to,list);
          if(res==-1){
            cout<<-1<<endl;
            return 0;
          }
        }else{
          if((A[to]^A[i])!=c){
            cout<<-1<<endl;
            return 0;
          }
        }
      }
      int ls=list.size();
      vector<int> bit(32);
      for(int i=0;i<ls;i++){
        int idx=0;
        while(list[i]){
          if(list[i]%2)bit[idx]++;
          idx++;
          list[i]/=2;
        }
      }
      for(int j=0;j<31;j++){
        if(ls-bit[j]<bit[j]){
          A[i]|=1<<j;
        }
      }
      seen2[i]=true;
      dfs2(i,A[i]);
    }
  }
  for(int i=0;i<N;i++){
    cout<<A[i]<<" ";
  }
  cout<<endl;
}
