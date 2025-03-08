#include<iostream>
using namespace std;
int main(){
	int N;cin>>N;
	int l=-1,r=-1;
	int ans=0;
	for(;N--;){
		int a;
		char s;
		cin>>a>>s;
		if(s=='L'){
			if(l!=-1){
				ans+=abs(a-l);
			}
			l=a;
		}else{
			if(r!=-1){
				ans+=abs(a-r);
			}
			r=a;
		}
	}
	cout<<ans<<endl;
}
