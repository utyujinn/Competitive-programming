#include<iostream>
using namespace std;

int main(){
	int A,B,C;
	cin>>A>>B>>C;
	if(B<C)B+=24;
	if(A<C)A+=24;
	if(A>C&&A<B)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
