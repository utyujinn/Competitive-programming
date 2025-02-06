#include<iostream>
using namespace std;
int N,Q;
int idx[1<<20];
int cnt[1<<20];
int main(){
	cin>>N>>Q;
	for(int i=1;i<=N;i++)idx[i]=i,cnt[i]=1;
	int ans = 0;
	for(;Q--;)
	{
		int op;cin>>op;
		if(op==1)
		{
			int p,h;cin>>p>>h;
			if(--cnt[idx[p]]==1)ans--;
			idx[p]=h;
			if(cnt[h]++==1)ans++;
		}
		else cout<<ans<<"\n";
	}
}
