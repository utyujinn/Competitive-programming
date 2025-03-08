#include<iostream>
#include<vector>
using namespace std;

int main(){
  int q;cin>>q;
  vector<int> st;
  for(int i=0;i<100;i++)st.push_back(0);
  for(;q--;){
    int com;cin>>com;
    if(com==1){
      int x;cin>>x;
      st.push_back(x);
    }else{
      cout<<st.back()<<endl;
      st.pop_back();
    }
  }
}
