#include<iostream>
#include<queue>
#include<unordered_set>
using namespace std;
unordered_set<string> list;

int main(){
	int N;cin>>N;
	string S,T;cin>>S>>T;
	N+=2;
	S+="..";
	T+="..";
	list.insert(S);
	queue<pair<string,int>> q;
	q.emplace(S,0);
	int ans=-1;
	while(!q.empty()){
		auto[A,cost]=q.front();q.pop();
		if(A==T){
			ans=cost;
			break;
		}
		int idx=0;
		while(true){
			if(A[idx]=='.')break;
			idx++;
		}
		for(int i=0;i<N-1;i++){
			if(A[i]!='.'&&A[i+1]!='.'){
				char t1=A[i],t2=A[i+1];
				A[idx]=t1,A[idx+1]=t2;
				A[i]='.',A[i+1]='.';
				if(list.find(A)==list.end()){
					list.insert(A);
					q.emplace(A,cost+1);
				}
				A[idx]='.',A[idx+1]='.';
				A[i]=t1,A[i+1]=t2;
			}
		}
	}
	cout<<ans<<endl;
}
