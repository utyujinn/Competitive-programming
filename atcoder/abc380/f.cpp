#include<iostream>
#include<set>
using namespace std;

bool cur_win(set<int> &A,set<int> &B,set<int> &C){
	/*
	cout<<"A:";
	for(auto a:A){
		cout<<a<<" ";
	}
	cout<<endl;
	cout<<"B:";
	for(auto b:B){
		cout<<b<<" ";
	}
	cout<<endl;
	cout<<"C:";
	for(auto c:C){
		cout<<c<<" ";
	}
	cout<<endl<<endl;
	*/
	if(A.size()==0){
		return false;
	}
	bool flag=false;
	set<int> AA=A;
	set<int> CC=C;
	for(auto n:AA){
		A.erase(n);
		C.insert(n);
		for(auto cn: CC){
			if(cn<n){
				C.erase(cn);
				A.insert(cn);
				flag|=cur_win(B,A,C);
				A.erase(cn);
				C.insert(cn);
			}
		}
		flag|=cur_win(B,A,C);
		C.erase(n);
		A.insert(n);
	}
//	cout<<(!flag?"win":"lose")<<endl;
	return !flag;
}

int main(){
	int N,M,L;
	cin>>N>>M>>L;
	set<int> A,B,C;
	for(int i=0;i<N;i++){
		int t;
		cin>>t;
		A.insert(t);
	}
	for(int i=0;i<M;i++){
		int t;
		cin>>t;
		B.insert(t);
	}
	for(int i=0;i<L;i++){
		int t;
		cin>>t;
		C.insert(t);
	}
	if(cur_win(A,B,C)){
		cout<<"Takahashi"<<endl;
	}
	else{
		cout<<"Aoki"<<endl;
	}
}
