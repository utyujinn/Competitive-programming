#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,q;
	cin>>n>>q;
	vector<int> list(n);
	for(int i=0; i<n;i++){
		list[i]=i;
	}
	vector<int> cnt(n,1);
	int ans=0;
	for(;q--;){
		int t;
		cin>>t;
		if(t==1){
			int p,h;
			cin>>p>>h;
			p--,h--;
			cnt[h]++;
			cnt[list[p]]--;
			if(cnt[list[p]]==1)ans--;
			if(cnt[h]==2)ans++;
			list[p]=h;
		}
		else{
			cout << ans << endl;
		}
	}
}
