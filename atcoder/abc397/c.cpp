#include<iostream>
using namespace std;
int A[3<<17];
int mp[3<<17];
bool used[3<<17];

int main(){
  int N;cin>>N;
  int ans=0,cnt=0;
  for(int i=0;i<N;i++){
    cin>>A[i];
    if(mp[A[i]]==0){
      cnt++;
    }
    mp[A[i]]=i+1;
  }
  if(mp[A[0]]!=1){
    cnt++;
    used[A[0]]=true;
  }
  ans=cnt;
  for(int i=1;i<N-1;i++){
    if(used[A[i]]==false){
      cnt++;
      used[A[i]]=true;
    }
    if(mp[A[i]]==i+1){
      cnt--;
    }
    ans=max(ans,cnt);
  }
  cout<<ans<<endl;
}
