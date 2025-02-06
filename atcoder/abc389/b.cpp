#include<iostream>
#include<vector>
using namespace std;

int main(){
	unsigned long x,sum=1;
	cin >> x;
	int i = 0;
	while(sum!=x){
		i++;
		sum *= i;
	}
	cout << i << endl;
}
