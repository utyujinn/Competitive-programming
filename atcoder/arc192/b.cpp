#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int N;
	cin>>N;
	vector<long> A(N);
	long sum=0;
	vector<int> list(2);
	for(int i=0;i<N;i++){
		cin>>A[i];
		list[A[i]%2]++;
	}
	if(list[0]<=2){
		if(N%2)cout<<"Fennec"<<endl;
		else cout<<"Snuke"<<endl;
	}else{
		int flag=0;
		if(list[1]&1)cout<<"Fennec"<<endl;
		else cout<<"Snuke"<<endl;
	}
}
