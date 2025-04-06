#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

void solve(){
  int n,k;cin>>n>>k;
  string s;cin>>s;
  string rs=s;
  reverse(rs.begin(),rs.end());
  if(k==0){
    for(int i=0;i<n;i++){
      if(s[i]<rs[i]){
        cout<<"Yes"<<endl;
        return;
      }else if(s[i]>rs[i]){
        cout<<"No"<<endl;
        return;
      }
    }
    cout<<"No"<<endl;
    return;
  }else if(k>=1){
    map<int,int> mp;
    for(int i=0;i<n;i++){
      mp[s[i]]++;
    }
    int cnt=0;
    for(auto [a,b]:mp){
      cnt++;
    }
    if(cnt>=2){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }
  return;
}

int main(){
  int t;cin>>t;
  for(int i=0;i<t;i++)
    solve();
}
