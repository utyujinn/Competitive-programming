//from description
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int H,W,N;
int main(){
	cin>>H>>W>>N;
	vector<pair<int,int>> RC(N);
	for(int i=0;i<N;i++){
		cin>>RC[i].first>>RC[i].second;
	}
	sort(RC.begin(),RC.end());
	vector<int> dp(N,1e9),id(N,-1),pre(N);
	for(int i=0;i<N;i++){
		int it=upper_bound(dp.begin(),dp.end(),RC[i].second)-dp.begin();
		dp[it]=RC[i].second;
		id[it]=i;
		pre[i]=(it?id[it-1]:-1);
	}
	int m=N-1;
	while(id[m]==-1)--m;
	vector<pair<int,int>> path={{H,W}};
	int now=id[m];
	while(now!=-1){
		path.push_back(RC[now]);
		now=pre[now];
	}
	path.emplace_back(1,1);
	reverse(path.begin(),path.end());
	string s;
	for(int i=0;i<(int)path.size()-1;i++){
		int d=path[i+1].first-path[i].first;
		int r=path[i+1].second-path[i].second;
		while(d--)s.push_back('D');
		while(r--)s.push_back('R');
	}
	cout<<m+1<<'\n'<<s<<endl;
}
