#include<iostream>
#include<vector>
using namespace std;

int main(){
	int N;
	long K;
	cin>>N>>K;
	vector<int> P(N);
	vector<int> IP(N);
	for(int i=0;i<N;i++){
		cin>>P[i];
		P[i]--;
		IP[P[i]]=i;
	}
	vector<vector<int>> dou(N,vector<int>(62));
	for(int i=0;i<N;i++){
		dou[i][0]=P[i];
		dou[i][1]=P[P[i]];
	}
	for(int j=2;j<62;j++){
		for(int i=0;i<N;i++){
			dou[i][j]=dou[IP[dou[i][j-1]]][j-1];
		}
	}
	for(int j=0;j<6;j++){
		cout<<j<<":";
		for(int i=0;i<N;i++){
			cout<<dou[i][j]+1<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<N;i++){
		long k=K;
		int a=P[i];
		int cnt=1;
		while(k>0){
			if(k%2){
				a=dou[IP[a]][cnt];
			}
			k/=2;
			cnt++;
		}
		cout<<a+1<<" ";
	}
	cout<<endl;
}
