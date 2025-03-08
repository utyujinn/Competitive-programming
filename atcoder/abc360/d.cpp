#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N,T;
int X[2<<17];
string S;
vector<int> list[2];

int main(){
	cin>>N>>T>>S;
	for(int i=0;i<N;i++){
		cin>>X[i];
		list[S[i]-'0'].push_back(X[i]);
	}
	for(int i=0;i<2;i++)sort(list[i].begin(),list[i].end());
	long ans=0;
	for(int i=0;i<list[0].size();i++){
		int l=lower_bound(list[1].begin(),list[1].end(),max((long)-(1<<30),(long)list[0][i]-2*T))-list[1].begin();
		int r=lower_bound(list[1].begin(),list[1].end(),list[0][i])-list[1].begin();
		ans+=r-l;
	}
	cout<<ans<<endl;
}
