#include<iostream>
using namespace std;

int main(){
	int R,G,B;cin>>R>>G>>B;
	string C;
	cin>>C;
	if(C=="Red"){
		cout<<min(G,B)<<endl;
	}else if(C=="Green"){
		cout<<min(R,B)<<endl;
	}else{
		cout<<min(R,G)<<endl;
	}
}
