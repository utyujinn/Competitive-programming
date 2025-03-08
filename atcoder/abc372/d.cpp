#include<iostream>
#include<set>
using namespace std;
int H[2<<17],ans[2<<17];

int main(){
	int N;cin>>N;
	set<int> list;
	int cnt=0;
	for(int i=0;i<N;i++){
		cin>>H[i];
		H[i]--;
	}
	for(int i=N-1;i>=1;i--){
		list.insert(H[i]);
		auto it=list.begin();
		while(*it<H[i]){
			it=list.erase(it);
		}
		ans[i-1]=list.size();
	}
	for(int i=0;i<N;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}
