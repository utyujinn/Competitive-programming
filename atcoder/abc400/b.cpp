#include<iostream>
using namespace std;

long pow(int a,int b){
  long ret=1;
  for(int i=0;i<b;i++){
    ret*=a;
  }
  return ret;
}

int main(){
  int N,M;
  cin>>N>>M;
  long X=0;
  for(int i=0;i<=M;i++){
    X+=pow(N,i);
    if(X>1e9){
      cout<<"inf"<<endl;
      return 0;
    }
  }
  cout<<X<<endl;
}
