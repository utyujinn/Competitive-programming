#include<iostream>
#include<set>
using namespace std;
set<int> h[2000],v[2000];
set<int> x[2];

int main(){
  int N,T;cin>>N>>T;
  for(int i=0;i<T;i++){
    int A;cin>>A;A--;
    h[A/N].insert(A);
    v[A%N].insert(A);
    if(A/N==A%N)x[0].insert(A);
    if(N-A/N-1==A%N)x[1].insert(A);
    if(h[A/N].size()==N||v[A%N].size()==N||x[0].size()==N||x[1].size()==N){
      cout<<i+1<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
}
