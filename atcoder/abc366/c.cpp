#include<iostream>
#include<map>
using namespace std;

int main(){
	int Q;
	cin>>Q;
	map<int,int> mp;
	int ans=0;
	for(;Q--;){
		int q;cin>>q;
		if(q==1){
			int x;cin>>x;
			if(mp[x]==0)ans++;
			mp[x]++;
		}
		else if(q==2){
			int x;cin>>x;
			if(mp[x]==1)ans--;
			mp[x]--;
		}else cout<<ans<<endl;
	}
}
