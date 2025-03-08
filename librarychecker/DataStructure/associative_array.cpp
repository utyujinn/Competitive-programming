#include<iostream>
#include<map>
using namespace std;

struct HashMap{
	Hashmap(){}
	long hash(long long key){
		return key%10000;
	}
	void set(long key,long value){
		long idx=hash(key);
		if(list[idx].first==-1)list[idx]=make_pair(key,value);
		else{
			long arr=hashmap[idx];
			for(int i=0;i<


template<typename T>
struct AA{
	T n;
	map<T,T> list;
	AA(T _n):n(_n){}
	void set(T k,T v){
		list[k]=v;
	}
	T get(T k){
		if(list.find(k)==list.end()){
			return n;
		}else{
			return list[k];
		}
	}
};

int main(){
	map<int,int> A;
	int Q;
	cin>>Q;
	AA<long> aa(0);
	for(;Q--;){
		int q;cin>>q;
		if(q==0){
			long k,v;cin>>k>>v;
			aa.set(k,v);
		}
		else{
			long k;cin>>k;
			cout<<aa.get(k)<<endl;
		}
	}
}
