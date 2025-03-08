#include<iostream>
using namespace std;
int N;

struct tk{
	int lt,rt,cnt;
}
set<tk> list;

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		int x;cin>>x;
		x--;
		tk tmp={x,x,1};
		list.insert(tmp);
	}
	int Q;cin>>Q;
	for(int i=0;i<Q;i++){
		int t,g;
		cin>>t>>g;


}
