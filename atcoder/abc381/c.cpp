#include<iostream>
using namespace std;

int main(){
	int N;
	string S;
	cin>>N>>S;
	int ans=0;
	int cnt=0,cnt2=0,flag=0;
	for(int i=0;i<N;i++){
		if(S[i]=='1' && S[i-1]=='1'){
			cnt2=0;
			flag=0;
			cnt++;
		}else if(S[i]=='1' && S[i-1]!='1'){
			cnt2=0;
			flag=0;
			cnt=1;
		}
		else if(S[i]=='/' && flag==0){
			flag=1;
			ans=max(ans,1+2*min(cnt,cnt2)); 
		}
		else if(S[i]=='2' && flag==1){
			cnt2++;
			ans=max(ans,1+2*min(cnt,cnt2)); 
		}
		else{
			cnt=0;
			cnt2=0;
			flag=0;
		}
	}
	cout<<ans<<endl;
}
