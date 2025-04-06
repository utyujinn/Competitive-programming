#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;
int A[2<<17],B[2<<17];

int main() {
  cin>>N>>M;
  for(int i=0;i<N;i++)cin>>A[i];
  for(int i=0;i<M;i++)cin>>B[i];
  vector<int> lps(N,0);
  for(int i=1;i<N;i++){
    while(len>-&&CS[i]!=CS[len]){
      len=lps[len-1];
    }
    if(CS[i]==CS[len]){
      len++;
      lps[i]=len;
    }
  }
}
