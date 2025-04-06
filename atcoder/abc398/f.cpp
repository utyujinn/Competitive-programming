#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  string S;
  cin>>S;
  string RS=S;
  reverse(RS.begin(),RS.end());
  string CS=RS+"#"+S;
  int n=CS.size();
  vector<int> lps(n,0);
  int len=0;
  for(int i=1;i<n;i++){
    while(len>0&&CS[i]!=CS[len]){
      len=lps[len-1];
    }
    if(CS[i]==CS[len]){
      len++;
      lps[i]=len;
    }
  }
  cout<<S+RS.substr(lps[n-1])<<endl;
  return 0;
}

