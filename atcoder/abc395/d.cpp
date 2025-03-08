#include<iostream>
#include<vector>
#include<set>
using namespace std;
int N,Q;
set<int> list[1<<20];
int pb[1<<20];
int bs[1<<20];
int sb[1<<20];

int main(){
	cin>>N>>Q;
	for(int i=0;i<N;i++){
		pb[i]=i;
		bs[i]=i;
		sb[i]=i;
	}
	for(;Q--;){
		int op;cin>>op;
		if(op==1){
			int a,b;cin>>a>>b;
			a--,b--;
			pb[a]=sb[b];
		}
		if(op==2){
			int a,b;cin>>a>>b;
			a--,b--;
			swap(sb[a],sb[b]);
			swap(bs[sb[a]],bs[sb[b]]);
		}
		if(op==3){
			int a;cin>>a;
			a--;
			cout<<bs[pb[a]]+1<<endl;;
		}
	}
}
