#include<iostream>
#include<algorithm>
#include<tuple>
using namespace std;
bool cast[2<<17];
tuple<int,int,int> AC[2<<17];

int main(){
  int N;cin>>N;
  for(int i=0;i<N;i++){
    int a,c;cin>>a>>c;
    AC[i]=make_tuple(a,c,i);
  }
  sort(AC,AC+N);
  int m=N;
  for(int i=1;i<N;i++){
    if(get<1>(AC[i-1])>get<1>(AC[i])){
      cast[get<2>(AC[i-1])]=true;
      m--;
    }
  }
  cout<<m<<endl;
  for(int i=0;i<N;i++){
    if(!cast[i])cout<<i+1<<" ";
  }
  cout<<endl;
}

