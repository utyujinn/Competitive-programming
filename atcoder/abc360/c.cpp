#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int A[1<<17],W[1<<17];
vector<int> box[1<<17];

int main(){
	int N;cin>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=0;i<N;i++)cin>>W[i];
	for(int i=0;i<N;i++){
		A[i]--;
		box[A[i]].push_back(W[i]);
	}
	int ans=0;
	for(int i=0;i<N;i++){
		if(box[i].size()>0){sort(box[i].begin(),box[i].end());
		for(int j=0;j<box[i].size()-1;j++){
			ans+=box[i][j];
		}
		}
	}
	cout<<ans<<endl;
}
