#include<iostream>
using namespace std;

struct BIT{
	vector<int> tree;
	BIT(int _N):N(_N),tree(_N,0){
	}
	void add(int idx,int &x){
		while(idx<=N){
			tree[idx-1]+=x;
			idx&=-idx;
		}
	}
	int get_sum(int idx){
		int ret=0;
		while(idx>0){
			ret+=tree[idx-1];
			idx-=idx&(-idx);
		}
		return ret;
	}
}

int main(){
	BIT(
}

