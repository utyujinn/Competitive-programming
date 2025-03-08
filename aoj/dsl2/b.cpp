#include<iostream>
#include<vector>
using namespace std;

struct BIT{
  int n;
  vector<long> bit[2];
  BIT(int _n) : n(_n+1){
    for(int p=0;p<2;p++){
      bit[p].assign(n,0);
    }
  }
  void add_sub(int p, int i, int x){
    i++;
    for(int idx=i;idx<=n;idx+=idx&(-idx)){
      bit[p][idx-1]+=x;
    }
  }
  void add(int i,int x){
    add_sub(0,i,x);
  }
  void add_range(int l,int r,int x){
    add_sub(0,l,-x*(l-1));
    add_sub(0,r,x*(r-1));
    add_sub(1,l,x);
    add_sub(1,r,-x);
  }
  long sum_sub(int p,int i){
    long s=0;
    i++;
    for(int idx=i;idx>0;idx-=idx&(-idx)){
      s+=bit[p][idx-1];
    }
    return s;
  }
  long sum(int i){
  	return sum_sub(0,i)+i*sum_sub(1,i);
  }
	long sum(int l,int r){
		return sum(r-1)-sum(l-1);
	}
  int get(int i){
    return sum(i)-sum(i-1);
  }
};

int main(){
	int n,q;cin>>n>>q;
	BIT bit(n);
	for(;q--;){
		int com;cin>>com;
		if(com==0){
			int s,t;cin>>s>>t;
			bit.add(s,t);
		}else{
			int s,t;cin>>s>>t;
			cout<<bit.sum(s,t+1)<<endl;
		}
	}
}
