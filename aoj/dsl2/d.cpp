#include<iostream>
#include<vector>
using namespace std;

struct RUQ{
	int N;
	vector<int> data,lazy;
	RUQ(int _N){
		int a=1;
		while(a<_N)a<<=1;
		N=a;
		data.assign(N*2,~0U>>1);
		lazy.assign(N*2,~0U>>1);
	}
	void eval(int k){
		if(lazy[k]==~0U>>1)return;
		if(k<N){
			lazy[k*2]=lazy[k];
			lazy[k*2+1]=lazy[k];
		}
		data[k]=lazy[k];
		lazy[k]=~0U>>1;
	}
	void update_sub(int l,int r,int x,int k,int al,int ar){
		eval(k);
		if(l>=ar||r<=al)return;
		else if(l<=al&&ar<=r){
			lazy[k]=x;
			eval(k);
		}
		else{
			eval(k);
			update_sub(l,r,x,k*2,al,(al+ar)/2);
			update_sub(l,r,x,k*2+1,(al+ar)/2,ar);
		}
	}
	void update(int l,int r,int x){
		update_sub(l,r,x,1,0,N);
	}
	int find_sub(int l,int r,int k,int al,int ar){
		if(l>=ar||r<=al)return ~0U>>1;
		else if(l<=al&&ar<=r){
			eval(k);
			return data[k];
		}
		else{
			eval(k);
			int gl=find_sub(l,r,k*2,al,(al+ar)/2);
			int gr=find_sub(l,r,k*2+1,(al+ar)/2,ar);
			return min(gl,gr);
		}
	}
	int find(int i){
		return find_sub(i,i+1,1,0,N);
	}
	void print(){
		for(int i=0;i<2*N;i++){
			cout<<data[i]<<(i==N*2-1?"\n":" ");
		}
	}
};

int main(){
	int n,q;
	cin>>n>>q;
	RUQ ruq(n);
	for(;q--;){
		int com;cin>>com;
		if(com==0){
			int s,t,x;cin>>s>>t>>x;
			ruq.update(s,t+1,x);
		}
		else{
			int i;cin>>i;
			cout<<ruq.find(i)<<endl;
		}
		//ruq.print();
	}
}
