#include<iostream>
#include<algorithm>
using namespace std;

pair<int,int> lr[5<<17];

int main(){
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    int l,r;cin>>l>>r;
    lr[i].first=l,lr[i].second=r;
  }
  sort(lr,lr+N);
  long ans=0;
  for(int i=0;i<N;i++){
    int ng=i,ok=N;
    while(ok-ng>1){
      int mid=(ok+ng)/2;
      if(lr[mid].first<=lr[i].second){
        ng=mid;
      }else{
        ok=mid;
      }
    }
    ans+=ng-i;
  }
  cout<<ans<<endl;
}
