#include<iostream>
using namespace std;
int N;
int num[1<<20];
int sum[1<<20];
int A[2<<17];

int main(){
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>A[i];
    num[A[i]]++;
  }
  for(int i=1;i<1<<20;i++){
    sum[i]=num[i]+sum[i-1];
  }
  long ans=0;
  for(int i=1;i<1<<20;i++){
    for(int j=i;j<1<<20;j+=i){
      ans+=(long)num[i]*(sum[min(j+i-1,(1<<20)-1)]-sum[j-1])*(j/i);
    }
    ans-=(long)num[i]*(num[i]+1)/2;
  }
  cout<<ans<<endl;
}
