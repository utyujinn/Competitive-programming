#include<iostream>
using namespace std;

long get(long x,long y){
  long ret=0;
  long X=x/4;
  long Y=y/2;
  ret+=8*X*Y;
  int mx=x%4;
  if(mx==1){
    ret+=mx*3*y

}

int main(){
  long A,B,C,D;
  cin>>A>>B>>C>>D;
  A+=1<<30;
  B+=1<<30;
  C+=1<<30;
  D+=1<<30;
  cout<<get(C,D)+get(A,B)-get(A,D)-get(C,B)<<endl;
}

