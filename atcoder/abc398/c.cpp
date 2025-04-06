#include<iostream>
#include<map>
using namespace std;
map<int,int> mp;
int A[3<<17];

int main(){
  int N;cin>>N;
  for(int i=0;i<N;i++){
    cin>>A[i];
    mp[A[i]]++;
  }
  int m=-1;
  for(auto[a,b]:mp){
    if(b==1)m=a;
  }
  for(int i=0;i<N;i++){
    if(A[i]==m)cout<<i+1<<endl;
  }
  if(m==-1)cout<<m<<endl;
}
