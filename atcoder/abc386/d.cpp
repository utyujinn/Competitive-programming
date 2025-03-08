#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
int N,M;

struct grid{
	int x,y;
	char c;
};

int main(){
	cin>>N>>M;
	vector<grid> list;
	for(int i=0;i<M;i++){
		int x,y;
		char c;
		cin>>x>>y>>c;
		x--,y--;
		grid tmp={x,y,c};
		list.push_back(tmp);
	}
	sort(list.begin(),list.end(),[](grid a,grid b)->bool{
			return tie(a.x,b.c)<tie(b.x,a.c);
		});
	int maxb=N-1;
	for(int i=0;i<M;i++){
		if(list[i].c=='B'){
			if(maxb<list[i].y){
				cout<<"No"<<endl;
				return 0;
			}
		}else{
			if(maxb>=list[i].y){
				maxb=list[i].y-1;
			}
		}
	}
	cout<<"Yes"<<endl;
}
