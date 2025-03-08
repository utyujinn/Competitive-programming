#include<iostream>
using namespace std;
int A[2<<17];

int main(){
	int N;long M;cin>>N>>M;
	long sum=0;
	for(int i=0;i<N;i++){
		cin>>A[i];
		sum+=A[i];
	}
	if(sum<=M)cout<<"infinite"<<endl;
	else{
		int ok=1<<30,ng=-1;
		while(ok-ng>1){
			int mid=(ok+ng)/2;
			sum=0;
			for(int i=0;i<N;i++){
				sum+=min(A[i],mid);
			}
			if(sum<=M)ng=mid;
			else ok=mid;
		}
		cout<<ng<<endl;
	}
}
