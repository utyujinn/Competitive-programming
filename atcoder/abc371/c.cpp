#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int N,MG,MH;
int u[30],v[30];
int a[30],b[30];
int A[8][8];

int main(){
	cin>>N>>MG;
	for(int i=0;i<MG;i++){
		cin>>u[i]>>v[i];
		u[i]--,v[i]--;
	}
	cin>>MH;
	for(int i=0;i<MH;i++){
		cin>>a[i]>>b[i];
		a[i]--,b[i]--;
	}
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			cin>>A[i][j];
		}
	}
	vector<int> P(N),IP(N);
	for(int i=0;i<N;i++){
		P[i]=i;
	}
	int ans=~0U>>1;
	do{
		for(int i=0;i<N;i++){
			IP[P[i]]=i;
		}
		set<pair<int,int>> list;
		for(int i=0;i<MG;i++){
			list.insert(make_pair(u[i],v[i]));
		}
		int tmp=0;
		for(int i=0;i<MH;i++){
			int na=P[a[i]],nb=P[b[i]];
			if(na>nb)swap(na,nb);
			auto nn=make_pair(na,nb);
			if(list.count(nn)){
				list.erase(nn);
			}else{
				tmp+=A[a[i]][b[i]];
			}
		}
		for(auto[x,y]:list){
			x=IP[x],y=IP[y];
			if(x>y)swap(x,y);
			tmp+=A[x][y];
		}
		ans=min(tmp,ans);
	}while(next_permutation(P.begin(),P.end()));
	cout<<ans<<endl;
}
