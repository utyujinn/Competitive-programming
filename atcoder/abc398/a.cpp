#include<iostream>
using namespace std;

int main(){
  int N;cin>>N;
  if(N%2==0){
  for(int i=0;i<N/2-1;i++){
    cout<<"-";
  }cout<<"==";
  for(int i=0;i<N/2-1;i++){
    cout<<"-";
  }
  }
  else{
  for(int i=0;i<N/2;i++){
    cout<<"-";
  }cout<<"=";
  for(int i=0;i<N/2;i++){
    cout<<"-";
  }
  }
  cout<<endl;
}
