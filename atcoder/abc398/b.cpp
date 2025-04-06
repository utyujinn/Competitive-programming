#include<iostream>
#include<map>
using namespace std;
map<int,int> mp;

int main(){
  for(int i=0;i<7;i++){
    int a;cin>>a;
    mp[a]++;
  }
  int t=0,s=0;
  for(auto[a,b]:mp){
    if(b==2)t++;
    if(b>=3)s++;
  }
  if(s>=2||(s>=1&&t>=1))cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
