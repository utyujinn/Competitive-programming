#include<iostream>
#include<vector>
using namespace std;
int N,K;
int dp[2][1001];//0->A,1->B
vector<pair<int,int>> list;//width,height

int main(){
	string S;
	cin>>N>>K>>S;
	int idx=0;
	list.emplace_back(1,~0U>>1);
	for(int i=0;i<N;i++){
		cin>>H;
		if(H>list[idx].second){
			long add=0;
			while(H>list[idx].second){
				if(H==list[idx-1].second){
					add+=list[idx].first*(H-list[idx].second);
					list[idx-1].first+=list[idx].first;
					list.pop_back();
				}else if(H<list[idx-1].second){
					list[idx].first++;
					list[idx].second=H;
				}else if(H>list[idx-1].second){
					add+=list[idx].first*(list[idx-1].second-list[idx].second);
					list[idx-1].first+=list[idx].first;
					list.pop_back();
				}
				add++;
				st+=add;
			}
		}else if(H==list[idx].second){
			st++;
			list[idx].first++;
		}else if(H<list[idx].second){
			st++;
			list.emplace_back(1,1);
			idx++;
		}
		cout<<st<<" ";
		}
	}
}
