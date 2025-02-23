#include<iostream>
#include<set>
using namespace std;
int d[9][2]={{0,0},{1,2},{2,1},{1,-2},{2,-1},{-1,2},{-2,1},{-2,-1},{-1,-2}};
int main(){
	long N,M;
	cin>>N>>M;
	set<pair<int,int>> list;
	long ans=N*N;
	for(;M--;){
		int a,b;
		cin>>a>>b;
		a--,b--;
		for(int i=0;i<9;i++){
			if(a+d[i][0]>=0&&a+d[i][0]<N&&b+d[i][1]>=0&&b+d[i][1]<N){
				auto tmp=make_pair(a+d[i][0],b+d[i][1]);
				if(!list.count(tmp)){
					ans--;
					list.insert(tmp);
				}
			}
		}
	}
	cout<<ans<<endl;
}
