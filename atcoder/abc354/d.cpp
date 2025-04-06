#include<iostream>
using namespace std;

long get(long x,long y){
  long ret=0;
  long X=x/4;
  long Y=y/2;
  int mx=x%4;
  int my=y%2;
  ret+=8*X*Y;
  switch(my){
    case 0:
      switch(mx){
        case 0:
          break;
        case 1:
          ret+=3*Y;
          break;
        case 2:
          ret+=6*Y;
          break;
        case 3:
          ret+=7*Y;
          break;
      }
      break;
    case 1:
      switch(mx){
        case 0:
          ret+=4*X;
          break;
        case 1:
          ret+=4*X+3*Y+2;
          break;
        case 2:
          ret+=4*X+6*Y+3;
          break;
        case 3:
          ret+=4*X+7*Y+3;
          break;
      }
      break;
  }
  return ret;
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

