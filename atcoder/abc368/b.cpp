#include<iostream>
#include<algorithm>
using namespace std;
int N;
int A[100];

int main(){
	cin>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	sort(A,A+N);
	reverse(A,A+N);
	int cnt=0;
	while(A[1]!=0){
		cnt++;
		A[0]--,A[1]--;
		sort(A,A+N);
		reverse(A,A+N);
	}
	cout<<cnt<<endl;
}
