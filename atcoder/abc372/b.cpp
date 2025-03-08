#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
	int m;
	cin>>m;
	vector<int> ans;
	for(int i=10;i>=0;i--){
		while(m/(int)pow(3,i)){
			ans.push_back(i);
			m-=(int)pow(3,i);
		}
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}
