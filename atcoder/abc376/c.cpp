#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;

int main(){
	cin>>N;
	vector<int> A(N),B(N-1);
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=0;i<N-1;i++)cin>>B[i];
	int ida=0;
	int idb=0;
	int ans=0;
	int cnt=0;
	sort(A.rbegin(),A.rend());
	sort(B.rbegin(),B.rend());
	while(true){
		if(A[ida]<=B[idb]){
			ida++,idb++;
		}else{
			cnt++;
			ans=A[ida];
			ida++;
			if(cnt==2)break;
		}
		if(ida==N)break;
		if(ida==N-1&&idb==N-1){
			ans=A[N-1];
			break;
		}
	}
	if(cnt==2)cout<<-1<<endl;
	else cout<<ans<<endl;
}
