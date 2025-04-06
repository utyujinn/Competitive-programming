#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<long> prime;
set<long> st;
bool isprime[1<<20];

int main(){
  for(int i=2;i<1<<20;i++){
    isprime[i]=true;
  }
  for(int i=2;i*i<1<<20;i++){
    if(isprime[i]){
      for(int j=i+i;j<1<<20;j+=i){
        isprime[j]=false;
      }
    }
  }
  for(int i=2;i<1<<20;i++){
    if(isprime[i]){
      prime.push_back(i);
    }
  }
  int N=prime.size();
  for(int i=0;i<N;i++){
    long first=prime[i]*prime[i];
    double dfirst=(double)prime[i]*prime[i];
    while(true){
      for(int j=i+1;j<N;j++){
        long second=prime[j]*prime[j];
        double dsecond=(double)prime[j]*prime[j];
        if(dfirst*dsecond>1LL<<40){
          break;
        }
        while(true){
          if(dfirst*dsecond<1LL<<40){
            st.insert(first*second);
          }else{
            break;
          }
          second*=prime[j]*prime[j];
          dsecond*=(double)prime[j]*prime[j];
        }
      }
      first*=prime[i]*prime[i];
      dfirst*=(double)prime[i]*prime[i];
      if(dfirst>1LL<<40){
        break;
      }
    }
  }
  int Q;cin>>Q;
  for(;Q--;){
    long A;cin>>A;
    long ok=1LL<<40,ng=0;
    while(ok-ng>1){
      long mid=(ok+ng)/2;
      auto it=st.lower_bound(mid);
      if(*it<=A){
        ng=mid;
      }else{
        ok=mid;
      }
    }
    auto it=st.lower_bound(ng);
    cout<<*it<<endl;
  }
}
