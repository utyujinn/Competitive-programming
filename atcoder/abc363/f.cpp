#include<iostream>
#include<vector>
using namespace std;
long N;

bool isPalindoromic(long N){
	vector<long> tmp;
	while(N){
		tmp.push_back(N%10);N/=10;
	}
	for(int i=0;i<N;i++){
		if(tmp[i]!=tmp[N-i-1])return false;
	}
	return true;
:

vector<long> divisor(long N){
	vector<long> ret;
	for(int i=2;i*i<=N;i++){
		if(N%i==0){
			while(N%i==0){
				ret.push_back(i);
				N/=i;
			}
		}
	}
	if(N!=1)ret.push_back(N);
	return ret;
}

int main(){
	cin>>N;
	vector<long> div=divisor(N);
	for(int i=0;i<div.size();i++)cout<<div[i]<<endl;
}
