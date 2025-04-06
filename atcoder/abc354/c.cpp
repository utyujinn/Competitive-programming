#include<iostream>
#include<algorithm>
#include<tuple>
using namespace std;
bool cast[2<<17];
tuple<int,int,int> CA[2<<17];

int main(){
  int N;cin>>N;
  for(int i=0;i<N;i++){
    int a,c;cin>>a>>c;
    CA[i]=make_tuple(c,a,i);
  }
  sort(CA,CA+N);
  int m=N;
  for(int i=1;i<N;i++){
    if(get<1>(CA[i-1])>get<1>(CA[i])){
      cast[get<2>(CA[i-1])]=true;
      m--;
    }
  }
  cout<<m<<endl;
  for(int i=0;i<N;i++){
    if(!cast[i])cout<<i+1<<" ";
  }
  cout<<endl;
}

