#include<iostream>
using namespace std;

int main(){
  int cnt=0;
  int H;cin>>H;
  int day=0;
  while(cnt<=H){
    cnt+=1<<day;
    day++;
  }
  cout<<day<<endl;
}
