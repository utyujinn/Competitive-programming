#include<iostream>
using namespace std;
int main(){
  long N,M;cin>>N>>M;
  long ans=0;
  long mod=998244353;
  for(long i=0;i<=60;i++){
    if(M&(1LL<<i)){
      ans=(ans+N/(1LL<<(i+1))*(1LL<<i))%mod;
      ans=(ans+max(N%(1LL<<(i+1))-(1LL<<i)+1,0LL))%mod;
    }
  }
  cout<<ans<<endl;
}
