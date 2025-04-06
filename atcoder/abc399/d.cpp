#include<iostream>
using namespace std;
int N;
int A[4<<17];
int B[2<<17][2],BB[2<<17][2];

void solve(){
  cin>>N;
  for(int i=0;i<2*N;i++){
    cin>>A[i];
    A[i]--;
  }
  for(int i=0;i<N;i++){
    B[i][0]=-1,BB[i][0]=-1;
    B[i][1]=-1,BB[i][1]=-1;
  }
  for(int i=0;i<2*N;i++){
    if(i==0){
      if(A[i+1]!=A[i]){
        B[A[i]][0]=N;
        B[A[i]][1]=A[i+1];
      }
    }if(i==2*N-1){
      if(A[i]!=A[i-1])
        BB[A[i]][0]=A[i-1];
    }else{
      if(A[i]!=A[i-1]&&A[i]!=A[i+1]){
        if(B[A[i]][0]==-1){
          B[A[i]][0]=A[i-1];
          B[A[i]][1]=A[i+1];
        }
        else{
          BB[A[i]][0]=A[i-1];
          BB[A[i]][1]=A[i+1];
        }
      }
    }
  }
  int ans=0;
  for(int i=0;i<N;i++){
    if(B[i][0]==i||B[i][1]==i){
    }else{
      if(B[i][0]==BB[i][0]&&B[i][0]!=-1&&B[B[i][0]][0]!=-1)ans++;
      if(B[i][0]==BB[i][1]&&B[i][0]!=-1&&B[B[i][0]][0]!=-1)ans++;
      if(B[i][1]==BB[i][0]&&B[i][1]!=-1&&B[B[i][1]][0]!=-1)ans++;
      if(B[i][1]==BB[i][1]&&B[i][1]!=-1&&B[B[i][1]][0]!=-1)ans++;
    }
  }
  cout<<ans/2<<endl;
}

int main(){
  int T;cin>>T;
  for(;T--;)solve();
}
