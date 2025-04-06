#include<iostream>
#include<set>
using namespace std;
int N,R,C;
string S;
int gr,gc;
set<pair<int,int>> st;

int main(){
  cin>>N>>R>>C>>S;
  st.insert(make_pair(0,0));
  for(int i=0;i<N;i++){
    if(S[i]=='N'){
      R++;
      gr++;
    }else if(S[i]=='S'){
      R--;
      gr--;
    }else if(S[i]=='W'){
      C++;
      gc++;
    }else{
      C--;
      gc--;
    }
    st.insert(make_pair(gr,gc));
    if(st.count(make_pair(R,C))){
      cout<<"1";
    }else{
      cout<<"0";
    }
  }
  cout<<endl;
}
