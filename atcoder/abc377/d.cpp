#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int MOD=998244353;

int main(){
	int N,M;
	cin>>N>>M;
	vector<pair<int,int>> LR;
	for(int i=0;i<N;i++){
		int a,b;
		cin>>a>>b;
		LR.emplace_back(a,b);
	}
	sort(LR.begin(),LR.end());
	int last=M+1;
	long ans=0;
	int cnt=M;
	for(int i=N-1;i>=0;i--){
		while(LR[i].first<cnt){
			int tmp=last-cnt;
			ans+=tmp;
			cnt--;
		}
		while(i-1>=0&&LR[i].first==LR[i-1].first){
			i--;
		}
		last=min(LR[i].second,last);
		int tmp=last-LR[i].first;
		ans+=tmp;
		cnt--;
	}
	while(cnt>=1){
		int tmp=last-cnt;
		ans+=tmp;
		cnt--;
	}
	cout<<ans<<endl;
}
