#include<iostream>
using namespace std;
int A[101];

int main(){
  int N,L,R;
  cin>>N>>L>>R;
  for(int i=0;i<N;i++){
    A[i+1]=i+1;
  }
  for(int i=L;i<=R;i++){
    A[i]=L+R-L-i+L;
  }
  for(int i=1;i<=N;i++){
    cout<<A[i]<<" ";
  }cout<<endl;
}
