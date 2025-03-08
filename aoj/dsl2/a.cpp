#include<iostream>
#include<vector>
using namespace std;

struct RMQ{
	int N;
	vector<int> data;
	RMQ(int _N){
		int a=1;
		while(a<_N)a<<=1;
		N=a;
		data.assign(2*N,~0U>>1);
	}
	void update(int i,int x){
		i+=N;
		data[i]=x;
		while(i>1){
			i/=2;
			data[i]=min(data[i*2],data[i*2+1]);
		}
	}
	int find_sub(int l,int r,int k,int al,int ar){
		if(al>=r||ar<=l)return ~0U>>1;
		else if(l<=al&&ar<=r)return data[k];
		else{
			int gl=find_sub(l,r,k*2,al,(al+ar)/2);
			int gr=find_sub(l,r,k*2+1,(al+ar)/2,ar);
			return min(gl,gr);
		}
	}
	int find(int l,int r){
		return find_sub(l,r,1,0,N);
	}
};

int main(){
	int n,q;cin>>n>>q;
	RMQ rmq(n);
	for(;q--;){
		int com;cin>>com;
		if(com==0){
			int x,y;cin>>x>>y;
			rmq.update(x,y);
		}else{
			int x,y;cin>>x>>y;
			cout<<rmq.find(x,y+1)<<"\n";
		}
	}
}
