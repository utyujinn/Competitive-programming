#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long hebi(long N){
	long ret=0;
	vector<int> dig;
	while(N){
		dig.push_back(N%10);
		N/=10;
	}
	reverse(dig.begin(),dig.end());
	for(int i=0;i<dig.size();i++){
		int f;
		f=dig[i]-1;
		for(int j=1;j<=f;j++){
			long cnt=1;
			for(int k=i+1;k<dig.size();k++){
				cnt*=j-1;
			}
			ret+=cnt;
			cout<<cnt<<endl;
		}
	}
	cout<<endl;
	for(int i=1;i<dig.size();i++){
		for(int j=1;j<9;j++){
			long cnt=1;
			for(int k=i+1;k<dig.size();k++){
				cnt*=j;
			}
			ret=cnt;
		cout<<cnt<<endl;
		}
	}
	cout<<ret<<endl<<endl;
	return ret;
}

int main(){
	long L,R;cin>>L>>R;
	cout<<hebi(R)-hebi(L-1)<<endl;
}
