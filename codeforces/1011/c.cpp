#include<iostream>
using namespace std;

void solve(){
  long long x,y;
  cin>>x>>y;
  long long k=0;
  for(int i=0;i<40;i++){
    if((x&(1LL<<i))&&(y&(1LL<<i))){
      int j=i-1;
      while((x&(1LL<<j))&&(y&(1LL<<j))&&j>=0){
        j--;
      }
      if((x&(1LL<<j))&&j>=0){
        while((x&(1LL<<j))&&j>=0){
          j--;
        }
      }
      else if((y&(1LL<<j))&&j>=0){
        while((y&(1LL<<j))&&j>=0){
          j--;
        }
      }
      j++;
      x+=1LL<<j;
      y+=1LL<<j;
      k+=1LL<<j;
    }
  }
  if((x&(1LL<<40))&&(y&(1LL<<40))){
    cout<<-1<<endl;
  }else{
    cout<<k<<endl;
  }
}

int main(){
  int t;cin>>t;
  for(int i=0;i<t;i++)
    solve();
}
