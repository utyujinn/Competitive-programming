#include<iostream>
using namespace std;

int main(){
  long N;cin>>N;
  for(int diff=1;diff<1<<20;diff++){
    long low=1;
    long high=1LL<<60;
    long cnt=0;
    while(high-low>1){
      long mid=(high+low)/2;
      long x=mid+diff,y=mid;
      double dx=(double)x,dy=(double)y;
      double dcnt = diff*(dx*dx+dx*dy+dy*dy);
      if(dcnt>1e18){
        high=mid;
        continue;
      }
      cnt=diff*(x*x+x*y+y*y);
      if(cnt<=N){
        low=mid;
      }else{
        high=mid;
      }
    }
    long x=low+diff,y=low;
    cnt=diff*(x*x+x*y+y*y);
    if(cnt==N){
      cout<<x<<" "<<y<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
}
