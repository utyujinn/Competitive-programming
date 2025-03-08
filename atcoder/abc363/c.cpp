#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int P[10];
vector<string> list;
bool used[10];
int N,K;
string S;

void dfs(string T){
	if(T.size()==N){
		list.push_back(T);
		return;
	}
	int i=0;
	while(i<N){
		if(!used[i]){
			used[i]=true;
			string n=T+S[i];
			dfs(n);
			used[i]=false;
			while(S[i]==S[i+1])i++;
		}
		i++;
	}
}

int main(){
	cin>>N>>K;
	cin>>S;
	int ans=0;
	sort(S.begin(),S.end());
	dfs("");
	for(auto T:list){
		bool flag2=false;
		for(int s=0;s<N-K+1;s++){
			int t=s+K-1;
			bool flag=true;
			int ts=s,tt=t;
			while(ts<=tt){
				if(T[ts]!=T[tt]){
					flag=false;
					break;
				}
				ts++,tt--;
			}
			if(flag)flag2=true;
		}
		ans+=flag2;
	}
	cout<<list.size()-ans<<endl;
}
