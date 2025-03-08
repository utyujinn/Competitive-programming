#include<iostream>
using namespace std;
int bit[31];

int main(){
	int N;cin>>N;
	long ans=0;
	for(int i=0;i<N;i++){
		int a;cin>>a;
		for(int j=0;j<31;j++){
			if(a&(1<<j)){
				bit[j]=i-bit[j];
			}
			ans+=(long)bit[j]*(1<<j);
			if(a&(1<<j)){
				bit[j]++;
			}
		}
	}
	cout<<ans<<endl;
}
