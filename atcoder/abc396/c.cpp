#include<iostream>
#include<algorithm>
using namespace std;
int B[2<<17],W[2<<17];

int main(){
  int N,M;cin>>N>>M;
  for(int i=0;i<N;i++)cin>>B[i];
  for(int i=0;i<M;i++)cin>>W[i];
  sort(B,B+N);
  sort(W,W+M);
  reverse(B,B+N);
  reverse(W,W+M);
  int bi=0,wi=0;
  long ans=0;
  long cnt=0;
  while(true){
    if(bi>=N&&wi>=M)break;
    if(bi==N){
      if(bi>wi&&wi!=M){
        cnt+=W[wi];
        wi++;
      }else{
        break;
      }
    }
    else if(wi==M){
      if(bi!=N){
        cnt+=B[bi];
        bi++;
      }else{
        break;
      }
    }
    else if(bi==wi){
      cnt+=B[bi];
      bi++;
    }else if(bi>wi){
      if(cnt+B[bi]>cnt+W[wi]){
        cnt+=B[bi];
        bi++;
      }else{
        cnt+=W[wi];
        wi++;
      }
    }
    ans=max(ans,cnt);
  }
  cout<<ans<<endl;
}
