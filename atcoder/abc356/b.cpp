#include<iostream>
using namespace std;
int A[100];

int main(){
  int N,M;cin>>N>>M;
  for(int i=0;i<M;i++)cin>>A[i];
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      int x;cin>>x;A[j]-=x;
    }
  }
  for(int i=0;i<M;i++){
    if(A[i]>0){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
}
