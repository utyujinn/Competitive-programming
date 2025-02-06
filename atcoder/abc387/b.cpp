#include<iostream>
#include<vector>
using namespace std;

int main(){
	int x;
	cin >> x;
	int ans = 0;
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j < 10; j++){
			if(i*j != x)ans+=i*j;
		}
	}
	cout << ans << endl;
}
