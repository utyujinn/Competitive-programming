#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int N,Q;
	cin>>N>>Q;
	vector<int> H(N);
	for(int i=0;i<N;i++)cin>>H[i];
	vector<pair<int,int>> list(Q);
	for(int i=0;i<Q;i++){
		int l,r;
		cin>>l>>r;
		r--;
		list.emplace_back(r,i);
	}
	sort(list.begin(),list.end());
	vector<int> dp(N+1,0);
	dp[0]=1<<30;
	int cnt=N-1;
	vector<int> ans(Q);
	for(int i=Q-1;i>=0;i--){
		while(list[i].first<cnt){
			int ok=0,ng=N+1;
			while(ng-ok>1){
				int mid=(ok+ng)/2;
				if(dp[mid]>=H[cnt])ok=mid;
				else ng=mid; 
			}
			dp[ng]=H[cnt];
			cnt--;
		}
		int ok=0,ng=N+1;
		while(ng-ok>1){
			int mid=(ok+ng)/2;
			if(dp[mid]>=H[list[i].first])ok=mid;
			else ng=mid; 
		}
		ans[list[i].second]=ok;
	}
	for(int i=0;i<Q;i++){
		cout<<ans[i]<<endl;
	}
}
