#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	long N;cin>>N;
	if(N<=10){
		cout<<N-1<<endl;
		return 0;
	}
	int dig=1;
	while(true){
		if(dig==1){
			N-=10;
		}else{
			long cnt=9;
			for(int i=0;i<(dig-1)/2;i++){
				cnt*=10;
			}
			N-=cnt;
			if(N<0){
				N+=cnt;
				break;
			}
		}
		dig++;
	}
	long ans=1;
	for(int i=0;i<(dig-1)/2;i++){
		ans*=10;
	}
	ans+=N-1;
	cout<<ans;
	vector<int> list;
	while(ans){
		list.push_back(ans%10);
		ans/=10;
	}
	//reverse(list.begin(),list.end());
	if(dig%2==0){
		for(int i=0;i<list.size();i++){
			cout<<list[i];
		}
	}else{
		for(int i=1;i<list.size();i++){
			cout<<list[i];
		}
	}
	cout<<endl;
}
