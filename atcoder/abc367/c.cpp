#include<iostream>
#include<vector>
using namespace std;
int N,K;
int R[10];

void dfs(int idx,vector<int> list){
	if(idx==N){
		int sum=0;
		for(int i=0;i<N;i++){
			sum+=list[i];
		}
		if(sum%K==0){
			for(int i=0;i<N;i++){
				cout<<list[i]<<" ";
			}
			cout<<endl;
		}
	}
	else{
		for(int i=1;i<=R[idx];i++){
			list.push_back(i);
			dfs(idx+1,list);
			list.pop_back();
		}
	}
}

int main(){
	cin>>N>>K;
	for(int i=0;i<N;i++)cin>>R[i];
	vector<int> list;
	dfs(0,list);
}
