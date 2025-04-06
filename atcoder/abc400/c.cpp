#include<iostream>
#include<cmath>
using namespace std;

int main(){
  long N;cin>>N;
  long ans=0;
  long ok=1e9,ng=0;
  while(ok-ng>1){
    long mid=(ok+ng)/2;
    if(mid*mid<=N/2){
      ng=mid;
    }else{
      ok=mid;
    }
  }
  ans+=ng;
  ok=1e9,ng=0;
  while(ok-ng>1){
    long mid=(ok+ng)/2;
    if(mid*mid<=N/4){
      ng=mid;
    }else{
      ok=mid;
    }
  }
  ans+=ng;
  cout<<ans<<endl;
}
