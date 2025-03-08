#include<iostream>
#include<vector>
using namespace std;
int N,K,H;
vector<pair<int,int>> list;//width,height

int main(){
	string S;
	cin>>N;
	int idx=2;
	list.emplace_back(1,~0U>>1);
	cin>>H;cout<<H+1<<" ";
	long st=H+1;
	list.emplace_back(1,H);
	list.emplace_back(1,1);
	for(int i=1;i<N;i++){
		cin>>H;
		long add=0;
		while(H>list[idx].second){
			if(H<list[idx-1].second){
				add+=(long)list[idx].first*(H-list[idx].second);
				list[idx].second=H;
			}else if(H>=list[idx-1].second){
				add+=(long)list[idx].first*(list[idx-1].second-list[idx].second);
				list[idx-1].first+=list[idx].first;
				list.pop_back();
				idx--;
			}
		}
		add++;
		st+=add;
		cout<<st<<" ";
		list.emplace_back(1,1);
		idx++;
	}
	cout<<endl;
}
