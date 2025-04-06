#include<iostream>
#include<vector>
#include<set>
using namespace std;
set<pair<int,int>> st;
vector<int> G[100];
int depth[100];
int U[100],V[100];

void dfs(int c,int d,int p){
  depth[c]=d%2;
  for(auto n:G[c]){
    if(n!=p){
      dfs(n,d+1,c);
    }
  }
}

int main(){
  int N;cin>>N;
  for(int i=0;i<N-1;i++){
    cin>>U[i]>>V[i];
    U[i]--,V[i]--;
    G[U[i]].push_back(V[i]);
    G[V[i]].push_back(U[i]);
  }
  dfs(0,0,-1);
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      if((depth[i]+depth[j])%2==1){
        st.insert(make_pair(i,j));
      }
    }
  }
  for(int i=0;i<N-1;i++){
    st.erase(make_pair(U[i],V[i]));
  }
  int cnt;
  if(st.size()%2==1){
    cout<<"First"<<endl;
    cnt=0;
  }else{
    cout<<"Second"<<endl;
    cnt=1;
  }
  while(true){
    int i=100,j=100;
    if(cnt){
      cin>>i>>j;
    }
    if(i==-1&&j==-1){
      break;
    }else{
      st.erase(make_pair(i-1,j-1));
    }
    auto it=st.begin();
    cout<<it->first+1<<" "<<it->second+1<<endl;
    st.erase(it);
    cnt=1;
  }
}
