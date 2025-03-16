#include<iostream>
using namespace std;
bool a[4];
int main(){
  int A,B;
  cin>>A>>B;
  a[A]=true,a[B]=true;
  if(A==B)cout<<-1<<endl;
  else {
    for(int i=1;i<=3;i++){
      if(!a[i])cout<<i<<endl;
    }
  }
}
