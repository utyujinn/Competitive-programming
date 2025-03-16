#include<iostream>
using namespace std;
int C[100];
int A[100][15];
char R[100];
bool isTrue[15];

int main(){
  int N,M,K;
  cin>>N>>M>>K;
  for(int i=0;i<M;i++){
    cin>>C[i];
    for(int j=0;j<C[i];j++){
      cin>>A[i][j];
      A[i][j]--;
    }
    cin>>R[i];
  }
  int ans=0;
  for(int i=0;i<1<<N;i++){
    for(int j=0;j<N;j++){
      if(i&(1<<j))isTrue[j]=true;
      else isTrue[j]=false;
    }
    bool flag=true;
    for(int j=0;j<M;j++){
      int cnt=0;
      for(int k=0;k<C[j];k++){
        if(isTrue[A[j][k]])cnt++;
      }
      if((cnt>=K)^(R[j]=='o')){
        flag=false;
        break;
      }
    }
    if(flag){
      ans++;
    }
  }
  cout<<ans<<endl;
}
