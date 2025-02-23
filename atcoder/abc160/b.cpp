#include<iostream>
using namespace std;

int main(){
	int x;
	cin>>x;
	long ans=0;
	ans+=(x/500)*1000;
	ans+=(x%500)/5*5;
	cout<<ans<<endl;
}
