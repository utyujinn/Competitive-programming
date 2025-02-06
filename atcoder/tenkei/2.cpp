#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	if(n%2==1)return 0;
	for(int i = (1<<n)-1; i >=0;  i--){
		vector<char> s(n);
		int cnt = 0;
		int flag = 1;
		for(int j = n-1; j >= 0; j--){
			if(i & (1<<j)){
				s[n-1-j] = '(';
				cnt ++;
			}
			else{
				s[n-1-j] = ')';
				cnt --;
			}
			if(cnt < 0){
				flag = 0;
				break;
			}
		}
		if(flag && (cnt == 0)){
			for(int j = 0; j < n; j++){
				cout << s[j];
			}
			cout << endl;
		}
	}
}
