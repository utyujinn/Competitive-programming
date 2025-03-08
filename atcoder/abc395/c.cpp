#include<iostream>
using namespace std;
int pr[1<<20];
int ans=1<<20;

int main(){
	int N;cin>>N;
	for(int i=0;i<1e6+1;i++){
		pr[i]=-1;
	}
	for(int i=0;i<N;i++){
		int a;cin>>a;
		if(pr[a]==-1)pr[a]=i;
		else {
			ans=min(ans,i-pr[a]+1);
		}
	}
	if(ans==1<<20)cout<<-1<<endl;
	else cout<<ans<<endl;
}
