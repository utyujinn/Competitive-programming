#include<iostream>
#include<algorithm>
using namespace std;
int N;
int P[100];
int PS[100];
int ans[100];

int main(){
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>P[i];
    PS[i]=P[i];
  }
  sort(PS,PS+N);
  reverse(PS,PS+N);
  for(int i=0;i<N;i++){
    if(i==0){
      for(int j=0;j<N;j++){
        if(P[j]==PS[i]){
          ans[j]=1;
        }
      }
    }else if(PS[i]!=PS[i-1]){
      for(int j=0;j<N;j++){
        if(P[j]==PS[i]){
          ans[j]=i+1;
        }
      }
    }
  }
  for(int i=0;i<N;i++){
    cout<<ans[i]<<endl;
  }
}
