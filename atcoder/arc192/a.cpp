#include<iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	if(N%4==0){
		cout<<"Yes"<<endl;
		return 0;
	}
	else if(N%4==2){
		vector<int> A(N);
		for(int i=0;i<N;i++)cin>>A[i];
		for(int i=0;i<N;i++){
			if(A[i]==1){
				if(A[(i==N-1?0:i+1)]==1){
					cout<<"Yes"<<endl;
					return 0;
				}
				if((i-prev)%2){

				}else{


			}
	}
	else{
		for(int i=0;i<N;i++){
			int a;
			cin>>a;
			if(a==1){
				cout<<"Yes"<<endl;
				return 0;
			}
		}
		cout<<"No"<<endl;
	}
}
