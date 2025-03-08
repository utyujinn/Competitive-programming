#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	vector<pair<int,int>> list;
	int N;cin>>N;
	for(int i=0;i<N;i++){
		int a;cin>>a;
		list.emplace_back(a,i);
	}
	sort(list.rbegin(),list.rend());
	cout<<1+list[1].second<<endl;
}
