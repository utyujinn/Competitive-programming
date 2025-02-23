#include<iostream>
#include<vector>
using namespace std;

int main(){
	int N;string S;
	cin>>N>>S;
	int cnt=0;
	for(int i=0;i<N;i++){
		if(S[i]=='1'){
			cnt++;
		}
	}
	int cnt2=0;
	vector<int> c(5);
	for(int i=0;i<N;i++){
		if(S[i]=='1'){
			for(int j=1;j<5;j++){
				c[j]=c[j-1];
			}
			c[0]=i;
			cnt2++;
			if(cnt2==cnt/2+2){
				break;
			}
		}
	}
	long ans=1LL<<60;
	for(int i=0;i<5;i++){
		int piv=c[i];
		int cnt3=0;
		long tmp=0;
		for(int j=0;j<N;j++){
			if(S[j]=='1'){
				tmp+=abs((piv-cnt/2)+cnt3-j);
				cnt3++;
			}
		}
		ans=min(ans,tmp);
	}
	cout<<ans<<endl;
}
