#include<iostream>
using namespace std;
int A[100];

int main(){
  int N;cin>>N;
  for(int i=0;i<N;i++){
    cin>>A[i];
    if(i>=2)if(A[i]==A[i-1]&&A[i-1]==A[i-2]){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
}
