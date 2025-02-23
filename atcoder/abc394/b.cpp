#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	vector<pair<int,string>> list;
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		list.emplace_back(s.size(),s);
	}
	sort(list.begin(),list.end());
	for(int i=0;i<N;i++){
		cout<<list[i].second;
	}cout<<endl;
}
