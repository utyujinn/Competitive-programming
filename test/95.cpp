#include<iostream>

using namespace std;

int main(){
	long a,b,k;
	cin >> a >> b >> k;
	if(a < k){
		cout << 0 << " ";
		if(a+b > k)cout << a+b-k << endl;
		else cout << 0 << endl;
	}else{
		cout << a-k << " " << b << endl;
	}
}
