#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

long hebi(long x){
	long tmp = x;
	int digits = 0;
	while(tmp!=0){
		digits++;
		tmp/=10;
	}
	vector<int> digit(digits);
	tmp = x;
	for(int i = digits-1; i >= 0; i--){
		digit[i] = tmp % 10;
		tmp /= 10;
	}
	long ans = 0;

	int flag = 1;
	for(int i = 1; i < digits; i++){
		if(digit[i] >= digit[0])flag = 0;
	}
	if(flag)ans++;

	cout << ans << endl;

	for(int i = 1; i < digits; i++){
		ans += min(digit[0], digit[i]) * pow(digit[0], digits-i-1);
	}

	cout << ans << endl;

	for(int i = digit[0]-1; i > 0; i--){
		ans += pow(i, digits-1);
	}

	cout << ans << endl;

	for(int i = 1; i < digits-1; i++){
		for(int j = 1; j <= 9; j++){
			ans += pow(j, i);
		}
	}

	cout << ans << endl;
	return ans;
}

int main(){
	long l,r;
	cin >> l >> r;
	cout << hebi(r)-hebi(l-1) << endl;
}
