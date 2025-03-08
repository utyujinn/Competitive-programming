#include<iostream>
#include<set>
using namespace std;

template<typename T>
struct PP{
	set<T> list;
	PP(){}
	void insert(T k){
		list.insert(k);
	}
	void erase(T k){
		list.erase(k);
	}
	bool find(T k){
		return list.find(k)!=list.end();
	}
	T lower_bound(T k){
		auto tmp=list.lower_bound(k);
		if(tmp==list.end())return -1;
		else return *tmp;
	}
	T under_max(T k){
		auto tmp=list.lower_bound(k);
		if(*tmp==k)return k;
		else if(tmp==list.begin())return -1;
		else return *--tmp;
	}
};

int main(){
	int N,Q;cin>>N>>Q;
	string T;cin>>T;
	PP<int> pp;
	for(int i=0;i<N;i++){
		if(T[i]=='1')pp.insert(i);
	}
	for(;Q--;){
		int c,k;cin>>c>>k;
		if(c==0)pp.insert(k);
		if(c==1)pp.erase(k);
		if(c==2){
			cout<<(pp.find(k)?1:0)<<endl;
		}
		if(c==3){
			cout<<pp.lower_bound(k)<<endl;
		}
		if(c==4){
			cout<<pp.under_max(k)<<endl;
		}
	}
}
