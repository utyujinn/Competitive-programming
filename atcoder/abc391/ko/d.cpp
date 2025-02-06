#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,W;
vector<pair<int,int>> Yi[2<<17];
int ans[2<<17];

int main(){
	cin>>N>>W;
	for(int i=0;i<N;i++){
		int x,y;cin>>x>>y;
		Yi[x-1].push_back(make_pair(y,i));
		ans[i]=2e9;
	}
	for(int x=0;x<W;x++){
		sort(Yi[x].begin(),Yi[x].end());
	}
	int need=0;
	for(int i=0;;i++){
		bool none=false;
		for(int x=0;x<W;x++){
			if(Yi[x].size()<=i){
				none=true;
				break;
			}
			else need=max(need,Yi[x][i].first);
		}
		if(none)break;
		else{
			for(int x=0;x<W;x++){
				int id=Yi[x][i].second;
				ans[id]=need;
			}
			need++;
		}
	}
	int Q;cin>>Q;
	for(;Q--;){
		int t,a;cin>>t>>a;a--;
		cout<<(t<ans[a]?"Yes\n":"No\n");
	}
}
