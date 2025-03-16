#include<iostream>
using namespace std;
int N,X;

int main(){
	cin>>N>>X;
  long sum=0;
  long height = 2LL<<60;
  long u=1LL<<60,d=1LL<<60;
	for(int i=0;i<N;i++){
    cin>>u>>d;
    sum+=u;
    sum+=d;
    u==min(u+X,u);
    d=min(d+X,d);
    height=min(height, u+d);
  }
  cout<<sum-height*N<<endl;
}
