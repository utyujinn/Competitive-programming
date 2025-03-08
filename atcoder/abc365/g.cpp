#include<iostream>
using namespace std;
set<int> list[2<<17];
int t[2<<17],p[2<<17];

int main(){
	int N,M;cin>>N>>M;
	vector<pair<int,int>> tmp(M);
	for(int i=0;i<M;i++){
		int t[i],p[i];cin>>t[i]>>p[i];p[i]--;
		list[p[i]].insert(t[i]);
		tmp[p[i]]++;
	}
	int lim=1000;
	map<int,vector<int>> big;
	for(int i=0;i<N;i++){
		map<int,int> prev;
		if(list[i].size()>lim){
			big[i].assign(N,0);
			int cnt=false;
			int pr=0;
			for(int j=0;j<M;j++){
				if(p[j]==i){
					pr=j;
					cnt^=1;
				}
				else if(cnt){
					auto it=prev.find(p[j]);
					if(it!=prev.end()){




	int Q;cin>>Q;
}
