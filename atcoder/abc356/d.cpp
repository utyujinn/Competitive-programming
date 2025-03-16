#include<iostream>
using namespace std;
int main(){
  unsigned long N,M;cin>>N>>M;
  unsigned long ans=0;
  long mod=998244353;
  for(unsigned long i=0;i<=60;i++){
    if(M&(1ULL<<i)){
      ans=((ans+N/(1ULL<<(i+1))*(1ULL<<i))%mod+min(N%(1ULL<<(i+1)),1ULL<<i))%998244353;
    }
  }
  cout<<ans<<endl;
}
