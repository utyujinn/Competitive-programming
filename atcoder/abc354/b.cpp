#include<iostream>
#include<algorithm>
using namespace std;
string S[100];

int main(){
  int N;cin>>N;
  int sumC=0;
  for(int i=0;i<N;i++){
    int C;
    cin>>S[i]>>C;
    sumC+=C;
  }
  sort(S,S+N);
  cout<<S[sumC%N]<<endl;
}

