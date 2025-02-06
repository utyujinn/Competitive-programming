#include<iostream>
using namespace std;

int main(){
	long long n;
	cin >> n;
	long long tmp;
	tmp = n*2;
	long long a = 1;
	long long cnt = 0;
	while(a*a < tmp){
		if(tmp % a ==0){
			if(a % 2){
				cnt++;
			}
			else if(a % 2 == 0 && n%a ==1){
				cnt++;
			}
		}
		a++;
	}
	cout << cnt << endl;
}
