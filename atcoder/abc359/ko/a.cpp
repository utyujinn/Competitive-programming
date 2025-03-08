#include<iostream>
#include<vector>
using namespace std;

int main(){
	int N;cin>>N;
	vector<pair<int,int> > S;
	long sum=0;
	for(int i=0;i<N;i++){
		int H;cin>>H;
		int len=1;
		while(!S.empty()&&S.back().first<=H){
			sum-=(long)S.back().first*S.back().second;
			len+=S.back().second;
			S.pop_back();
		}
		S.push_back(make_pair(H,len));
		sum+=(long)H*len;
		cout<<sum+1<<(i==N-1?"\n":" ");
	}

}
