#include<iostream>
#include<set>
using namespace std;
int A[100];
char B[100];
bool ans[100];

int main(){
	int N,M;
	cin>>N>>M;
	set<int> list;
	for(int i=0;i<M;i++){
		cin>>A[i]>>B[i];
		if(!list.count(A[i])&&B[i]=='M'){
			ans[i]=true;
			list.insert(A[i]);
		}
		if(B[i]=='M')list.insert(A[i]);
	}
	for(int i=0;i<M;i++){
		cout<<(ans[i]?"Yes":"No")<<endl;
	}
}
