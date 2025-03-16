#include<iostream>
#include<algorithm>
using namespace std;
int A[100],B[100];
int AB[200];

int main(){
  int N,M;cin>>N>>M;
  for(int i=0;i<N;i++)cin>>A[i];
  for(int i=0;i<M;i++)cin>>B[i];
  for(int i=0;i<N;i++)AB[i]=A[i];
  for(int i=N;i<N+M;i++)AB[i]=B[i-N];
  sort(A,A+N);
  sort(B,B+M);
  sort(AB,AB+N+M);
  for(int i=0;i<N-1;i++){
    for(int j=0;j<N+M-1;j++){
      if(A[i]==AB[j]&&A[i+1]==AB[j+1]){
        cout<<"Yes"<<endl;
        return 0;
      }
    }
  }
  cout<<"No"<<endl;
}
