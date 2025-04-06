#include<iostream>
using namespace std;
int a[5000];
int l[5000],r[5000];

void solve(){
  int n;cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int cl=n;
  int l1=-1;
  int cnt=0;
  for(int i=0;i<n;i++){
    if(i==n-1){
      if(a[i]==0){
        l[cnt]=1;
        r[cnt]=i-(n-cl);
        cnt++;
        cl=2;
      }
    }
    if(a[i]!=0){
      if(l1==-1){
        if(i==0)
          l1=i;
        else{
          l[cnt]=0;
          r[cnt]=i;
          cl-=i;
          cnt++;
          l1=i;
        }
      }
      else if(l1==i-1){
        l1=i;
      }
      else{
        l[cnt]=l1-(n-cl);
        r[cnt]=i-1-(n-cl);
        cl-=(i-1-l1);
        l1=i;
        cnt++;
      }
    }else{
      if(l1==i-2){
        l[cnt]=i-1-(n-cl);
        r[cnt]=i-(n-cl);
        cl-=1;
        l1=i;
        cnt++;
      }
    }
  }
  if(cl>1){
    l[cnt]=0;
    r[cnt]=cl-1;
    cnt++;
  }
  cout<<cnt<<endl;
  for(int i=0;i<cnt;i++){
    cout<<l[i]+1<<" "<<r[i]+1<<endl;
  }
}

int main(){
  int t;cin>>t;
  for(int i=0;i<t;i++)
    solve();
}
